#!/usr/bin/env python

'''
Installs the code in the current directory to a FRC cRio-based Robot via FTP

Usage: run install.py, and it will upload to the bot
'''

import os
import ftplib
import sys


my_team_number = 2423


def get_robot_host(team_number):
    '''Given a team number, determine the address of the robot'''
    return '10.%d.%d.2' % (team_number / 100, team_number % 100 )
    

def reboot_crio():
    ''' 
        Send the reboot command to any cRios connected on the network
        -> Extracted from https://github.com/rbmj/netconsole, license unknown
    '''

    # ports
    UDP_IN_PORT=6666
    UDP_OUT_PORT=6668

    out = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
    out.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    out.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    out.bind( ('',UDP_OUT_PORT) ) # bind is necessary for escoteric reasons stated on interwebs
    out.sendto(b'\nreboot\n', ('255.255.255.255', UDP_OUT_PORT))


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
        try:
            self.ftp.quit()
        except Exception:
            pass # ignore this error

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

def wait():
    try:
        import msvcrt
        print("Press any key to continue")
        msvcrt.getch()
    except Exception:
        pass


if __name__ == '__main__':

    installer = None

    if sys.version_info[0] < 3:
        response = str(raw_input( 'Upload code to robot for team %d? ' % my_team_number  )).strip().lower()
    else:
        response = str(input( 'Upload code to robot for team %d? ' % my_team_number  )).strip().lower()

    if response != 'y' and response != 'yes':
        print("Not uploading code")
        wait()
        exit(1)
        
    robot_host = get_robot_host( my_team_number )

    try:
        installer = RobotCodeInstaller( robot_host )
    except Exception as e:
        print("Could not connect to robot FTP server %s: %s" % (robot_host, e))
        wait()
        exit(1)

    installer.upload_directory( '/py', '.', verbose=True)

    installer.close()
    
    # ask the user to reboot after installation?
    while True:
        if sys.version_info[0] < 3:
            yn = str(raw_input("Reboot robot? [y/n]")).strip().lower()
        else:
            yn = str(input("Reboot robot? [y/n]")).strip().lower()
            
        if yn == 'y':
            reboot_crio()
            break
        elif yn == 'n':
            break
    
    wait()
