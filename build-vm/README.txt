build-vm for RobotPy
====================

This is a vagrant-based VM that allows you to install all of the build 
dependencies for RobotPy so that you can build it from source.

This has been tested on OSX and Linux, but it should run equally well on
Windows platforms. File a bug report if you find this to not be the case.

Building the VM
===============

Host software requirements
--------------------------

The VM guest is a 64-bit host, as the GCC deb files only are 64-bit builds.
You may be able to run 64-bit guests on a 32-bit host, but there are
specific requirements that virtualbox has, and some problems have been
reported in that configuration. Search the internet for more details.

1. Install Virtualbox 4.2.16 or greater
   * Any newish version will work, but there are vagrant incompatibility
     issues with older versions of virtualbox, so stay newer
2. Install Vagrant [http://www.vagrantup.com]
   * Version 1.2 or greater should work, but definitely get at least 1.3.5
3. You need to install the correct vagrant plugins:
       
       $ vagrant plugin install vagrant-berkshelf 


Start the VM
------------

Open up a command prompt/terminal and run the following commands.

    $ cd <this directory>
    $ vagrant up
    
If all is well, a bunch of stuff will happen and you'll have a VM that will
have the necessary tools to build RobotPy on the cRio. You can access the
VM by doing:

    $ vagrant ssh

Keep in mind that starting the VM the first time may take a *long* time,
particularly because installing the base VM involves downloading hundreds
of megabytes. On my Core i5-2400, it took around 900s. Your milage may 
vary.

After the VM is brought up the first time, subsequent invocations of the
'up' command should be significantly faster, since everything is already
set up for you.

To shutdown the vm, you can do:

    $ vagrant halt
    
Avoid using the `vagrant destroy` command, as you will have to bring
everything back up from scratch again.


Building RobotPy
================

The RobotPy source code is mapped to ~/robotpy . You can execute the
following commands to build the source tree on the build VM. 

    $ mkdir ~/robotpy-build
    $ cd ~/robotpy-build
    $ frcmake ~/robotpy
    $ make

To copy the build output to ~/robotpy-build/dist

    $ make install
    
To build a binary release package:

    $ make package

After you execute this, you will have a RobotPy zip file at ~/robotpy-build
that will contain the RobotPy distribution package.

To copy the package to your machine, just use the following command:

    $ cp RobotPy-xxxx.zip /vagrant

The /vagrant directory is mapped to the folder that this README file resides
in, and you will find the zipfile there on the host machine.
