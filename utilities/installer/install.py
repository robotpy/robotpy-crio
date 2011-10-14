#!/usr/bin/env python

'''
Installs the code in ./robot to a FRC cRio-based Robot via FTP

Usage: run install.py, and it will upload 
'''

import os
import ftplib
import sys
from optparse import OptionParser



def get_robot_host(team_number):
    '''Given a team number, determine the address of the robot'''
    return '10.%d.%d.2' % (team_number / 100, team_number % 100 )


class RobotCodeInstaller(object):
    """
        Use this class to create programs that automatically upload your 
        python code to the robot in the right place without having
        to deal with an FTP client
        
        Example:
        
            from install import RobotCodeInstaller, get_robot_host
            
            installer = None
            my_team_number = 2423
            
            try:
                installer = RobotCodeInstaller( get_robot_host( my_team_number ) )
            except Exception as e:
                print("Could not connect to robot FTP server %s: %s" % (robot_host, e))
                exit(1)
            
            installer.upload_directory( '/py', '.')
            
            installer.close()
    """

    def __init__(self, robot_host, username='FRC', password='FRC', timeout=5):
        self.ftp = ftplib.FTP(robot_host, username, password, '', timeout)
        
    def close(self):
        self.ftp.quit()
    
    def upload_directory( self, remote_root, local_root, recursive=True, verbose=False, skip_special=True ):
        '''
            Parameters:
            
                remote_root:
                    The remote directory to upload files to 
                
                local_root:
                    The local directory to upload files from
                
                recursive:
                    Set to true to recursively walk local_root to upload files
                
                verbose:
                    Set to true to output the name of each file as it is 
                    being uploaded
                    
                skip_special:
                    Don't upload .pyc, .git, .svn, .hg directories
        '''

        # save cwd
        cwd = os.path.abspath( os.getcwd() )
        
        if not os.path.isdir( local_root ):
            print("ERROR: Local root directory %s does not exist" % local_root )
            return False
            
        os.chdir( local_root )
        
        try:
            self.ftp.cwd( remote_root )
        except ftplib.error_perm as msg:
            print("ERROR: Accessing remote directory %s failed: %s" % (remote_root, msg))
            return False
            
        has_error = False
    
        for root, dirs, files in os.walk( '.' ):
        
            # skip .svn, .git, .hg directories
            if skip_special:
                for d in dirs[:]:
                    if d in ['.svn', '.hg', '.git']:
                        dirs.remove(d)
        
            sys.stdout.write(root + ': ')
            if verbose:
                sys.stdout.write('\n')
        
            remote_files = []
        
            try:
                remote_files = self.ftp.nlst( root )
            except ftplib.error_perm:
                # directory must not exist, right?
                try:
                    self.ftp.mkd( root )
                    if verbose:
                        print( 'MKDIR ' + root )
                except ftplib.error_perm as msg:
                    print("ERROR: Creating directory %s failed: %s" % (root, msg))
                    break
                    
            for fn in files:
            
                filename = os.path.join( root, fn )
                r, ext = os.path.splitext( fn )
            
                # if this accidentally got in there, don't upload it
                if skip_special and ext == '.pyc':
                    continue
            
                # for each py file, delete a pyc file associated with it
                if ext == '.py' and (r + '.pyc') in remote_files:
                    try:
                        self.ftp.delete( r + '.pyc' )
                        if verbose:
                            print('DELETE ' + r + '.pyc')
                    except Exception:
                        pass
                        
                # upload the file already!
                with open(filename, 'rb') as stor_file:
                    try:
                        #
                        self.ftp.storbinary( 'STOR ' + filename, stor_file )
                        
                        if verbose:
                            print( 'STOR ' + filename )
                        else:
                            sys.stdout.write('.')
                            sys.stdout.flush()
                    except ftplib.error_perm as msg:
                        print("ERROR writing %s: %s" % (filename, msg ))
                        has_error = True
                        break
                    except IOError as msg:
                        print("ERROR reading from %s: %s" % (filename, msg))
                        has_error = True
                        break
                                            
            sys.stdout.write('\n')
        
            if has_error or not recursive:
                break
    
        # restore local cwd
        os.chdir( cwd )
        return True



if __name__ == '__main__':

    parser = OptionParser('Usage: %program [remote_host]')
    parser.add_option('-v', '--verbose', dest='verbose', 
                        help='Verbose output', action='store_true', default=False)
    parser.add_option('-t', '--team', dest='team_number', help='Team number', default=None)
    
    
    parser.add_option('--remote-root', dest='remote_root', 
                        help='Remote root directory (default: %default)', 
                        default='/')
                        
    parser.add_option('--local-root', dest='local_root', 
                        help='Local root directory (default: %default)', 
                        default=os.path.join( os.path.dirname(__file__), 'robot' ) )
    
    (options, args) = parser.parse_args()

    robot_host = None
    
    if len(args) == 1:
        robot_host = args[0]
    elif len(args) != 0:
        parser.error("Invalid arguments passed")

    # banner message
    print( "Robot code uploader v1.0" )
    
    
    if robot_host is None:
        # if the team number hasn't been specified in an option, then
        # ask the user for the team number. 
        team_number = options.team_number
        
        while team_number is None:
            try:
                team_number = int(input('Team number? '))
            except ValueError:
                pass
        
        # determine the host name from the team number
        robot_host = '10.%d.%d.2' % (team_number / 100, team_number % 100 )
    
    # ok, we're ready. Process the manifest and upload it 
    
    try:
        installer = RobotCodeInstaller( robot_host )
    except Exception as e:
        print("Could not connect to robot FTP server %s: %s" % (robot_host, e))
        exit(1)
    
    installer.upload_directory( options.remote_root, options.local_root, verbose=options.verbose )
    
    installer.close()
    
