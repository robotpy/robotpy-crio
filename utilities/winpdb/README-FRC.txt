


Winpdb - A GPL Python Debugger

Contact: Dustin Spicuzza
Email:   dustin@virtualroadside.com
Website: http://www.virtualroadside.com/FRC/
Version: 1.4.8-FRC


Winpdb is a python debugger that can be used to debug python code on a
remote system. The enclosed version of Winpdb has been modified to work
for RobotPy, a version of python intended to be used in the FIRST Robotics
Competition. 

Refer to the Winpdb website for usage notes not specific to FRC.


Installation:

    Copy rpdb2.py to somewhere that the python interpreter will find it:
    
        - Either the same directory as your Robot.py file ( /c/py )
        - OR /c/lib/python31/site-packages
    
    Add the following import to your robot.py file:
    
        import rpdb2

    And then add the following function to your run() function:
    
        rpdb2.start_embedded_debugger()
        
Usage:

    Launch Winpdb.py on your development machine, and then click 
    File -> Password, and set the password to 'FRC'. When your script
    is ready to be attached (a message will be displayed in the 
    netconsole output of your robot), then click File -> Attach, and
    set the IP address to '10.xx.xx.2' where xx.xx is your team number.
    You should see your robot.py script show up in the list, and so click
    it and you're set to go. 
    
    For actually using Winpdb, refer to the Winpdb website :) 
        
Important notes:

    - DO NOT add the start_embedded_debugger() function call to the
    main body of your script, otherwise you will not be able to attach
    to the program until the code begins running (by default, Winpdb 
    waits for 5 minutes for a debugger to attach before continuing
    execution)
    
    - The encryption/digest functions don't seem to work correctly
    on RobotPy yet, so they have been stripped from this version of
    Winpdb. This means you MUST use the password 'FRC' to attach to
    the debuggee, and all communications are in the clear (but FRC
    robots shouldn't be on public networks anyways, so this should
    not be an issue)
    
    - Make sure you take the debugger out when you go to competition!