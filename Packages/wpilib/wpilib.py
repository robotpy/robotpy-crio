from _wpilib import *

class RobotBase:
    def __init__(self):
        self.ds = DriverStation.GetInstance()
        self.watchdog = GetWatchdog()

    def IsSystemActive(self):
        return IsSystemActive()

    def GetWatchdog(self):
        return GetWatchdog()

    def IsEnabled(self):
        return IsEnabled()

    def IsDisabled(self):
        return IsDisabled()

    def IsAutonomous(self):
        return IsAutonomous()

    def IsOperatorControl(self):
        return IsOperatorControl()

    def IsNewDataAvailable(self):
        return IsNewDataAvailable()

class SimpleRobot(RobotBase):
    """The SimpleRobot class is intended to be subclassed by a user creating
    a robot program. Overridden Autonomous() and OperatorControl() methods
    are called at the appropriate time as the match proceeds. In the
    current implementation, the Autonomous code will run to completion
    before the OperatorControl code could start."""

    def RobotInit(self):
        print("Default RobotInit() method... Overload me!")

    def Disabled(self):
        print("Default Disabled() method... Overload me!")

    def Autonomous(self):
        print("Default Autonomous() method... Overload me!")

    def OperatorControl(self):
        print("Default OperatorControl() method... Overload me!")

    def StartCompetition(self):
        self.RobotInit()
        while True:
            if self.IsDisabled():
                self.Disabled()
                while self.IsDisabled():
                    Wait(0.01)
            elif self.IsAutonomous():
                self.Autonomous()
                while self.IsAutonomous() and self.IsEnabled():
                    Wait(0.01)
            else:
                self.OperatorControl()
                while self.IsOperatorControl() and self.IsEnabled():
                    Wait(0.01)

class IterativeRobot(RobotBase):
    """IterativeRobot implements a specific type of Robot Program
    framework, extending the RobotBase class.

    The IterativeRobot class is intended to be subclassed by a user
    creating a robot program.

    This class is intended to implement the "old style" default code, by
    providing the following functions which are called by the main loop,
    StartCompetition(), at the appropriate times:

    RobotInit() -- provide for initialization at robot power-on

    Init() functions -- each of the following functions is called once
    when the appropriate mode is entered:
     - DisabledInit()   -- called only when first disabled
     - AutonomousInit() -- called each and every time autonomous is entered
                           from another mode
     - TeleopInit()     -- called each and every time teleop is entered
                           from another mode

    Periodic() functions -- each of these functions is called iteratively
    at the appropriate periodic rate (aka the "slow loop").  The default
    period of the iterative robot is synced to the driver station control
    packets, giving a periodic frequency of about 50Hz (50 times per
    second).
     - DisabledPeriodic()
     - AutonomousPeriodic()
     - TeleopPeriodic()

    Continuous() functions -- each of these functions is called repeatedly
    as fast as possible:
     - DisabledContinuous()
     - AutonomousContinuous()
     - TeleopContinuous()
    """

    def __init__(self):
        RobotBase.__init__(self)
        self._disabledInitialized = False
        self._autonomousInitialized = False
        self._teleopInitialized = False
        self._period = 0.0
        self._mainLoopTimer = Timer()

    def SetPeriod(self, period):
        """Set the period for the periodic functions.

        period: The period of the periodic function calls.  0.0 means sync
        to driver station control data.
        """
        if period != 0.0:
            # Not syncing with the DS, so start the timer for the main
            # loop
            self._mainLoopTimer.Reset()
            self._mainLoopTimer.Start()
        else:
            # Syncing with the DS, don't need the timer
            self._mainLoopTimer.Stop()
        self._period = period

    def GetPeriod(self):
        """Get the period for the periodic functions.
        Returns 0.0 if configured to syncronize with DS control data packets.
        Otherwise returns period of the periodic function calls."""
        return self._period

    period = property(GetPeriod, SetPeriod, None,
                      "Period for the periodic functions.")

    def GetLoopsPerSec(self):
        """Get the number of loops per second for the IterativeRobot.
        Returns frequency of the periodic function calls."""
        return 1.0 / self._period

    def StartCompetition(self):
        """Provide an alternate "main loop" via StartCompetition().

        This specific StartCompetition() implements "main loop" behavior
        like that of the FRC control system in 2008 and earlier, with a
        primary (slow) loop that is called periodically, and a "fast loop"
        (a.k.a. "spin loop") that is called as fast as possible with no
        delay between calls."""

        # first and one-time initialization
        self.RobotInit()

        # loop forever, calling the appropriate mode-dependent function
        while True:
            # Call the appropriate function depending upon the current
            # robot mode
            if self.IsDisabled():
                # call DisabledInit() if we are now just entering disabled
                # mode from either a different mode or from power-on
                if not self._disabledInitialized:
                    self.DisabledInit()
                    self._disabledInitialized = True
                    # reset the initialization flags for the other modes
                    self._autonomousInitialized = False
                    self._teleopInitialized = False
                if self.NextPeriodReady():
                    self.DisabledPeriodic()
                self.DisabledContinuous()
            elif self.IsAutonomous():
                # call AutonomousInit() if we are now just entering
                # autonomous mode from either a different mode or from
                # power-on
                if not self._autonomousInitialized:
                    self.AutonomousInit()
                    self._autonomousInitialized = True
                    # reset the initialization flags for the other modes
                    self._disabledInitialized = False
                    self._teleopInitialized = False
                if self.NextPeriodReady():
                    self.AutonomousPeriodic()
                self.AutonomousContinuous()
            else:
                # call TeleopInit() if we are now just entering teleop mode
                # from either a different mode or from power-on
                if not self._teleopInitialized:
                    self.TeleopInit();
                    self._teleopInitialized = True
                    # reset the initialization flags for the other modes
                    self._disabledInitialized = False
                    self._autonomousInitialized = False
                if self.NextPeriodReady():
                    self.TeleopPeriodic()
                self.TeleopContinuous()

    def NextPeriodReady(self):
        """Determine if the periodic functions should be called.

        If self.period > 0.0, call the periodic function every self.period as
        compared to Timer.Get().  If self.period == 0.0, call the periodic
        functions whenever a packet is received from the Driver Station, or
        about every 20ms.

        TODO: Decide what this should do if it slips more than one cycle.
        """
        if self._period > 0.0:
            return self.mainLoopTimer.HasPeriodPassed(self.period)
        else:
            return self.ds.IsNewControlData()

    def RobotInit(self):
        print("Default RobotInit() method... Overload me!")

    def DisabledInit(self):
        print("Default DisabledInit() method... Overload me!")

    def AutonomousInit(self):
        print("Default AutonomousInit() method... Overload me!")

    def TeleopInit(self):
        print("Default TeleopInit() method... Overload me!")

    def DisabledPeriodic(self):
        print("Default DisabledPeriodic() method... Overload me!")

    def AutonomousPeriodic(self):
        print("Default AutonomousPeriodic() method... Overload me!")

    def TeleopPeriodic(self):
        print("Default TeleopPeriodic() method... Overload me!")

    def DisabledContinuous(self):
        print("Default DisabledContinuous() method... Overload me!")

    def AutonomousContinuous(self):
        print("Default AutonomousContinuous() method... Overload me!")

    def TeleopContinuous(self):
        print("Default TeleopContinuous() method... Overload me!")

