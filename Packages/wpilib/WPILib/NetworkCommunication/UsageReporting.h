
#ifndef __UsageReporting_h__
#define __UsageReporting_h__

#include <vxWorks.h>

#define kUsageReporting_version 1

namespace nUsageReporting
{
    typedef enum
    {
        kResourceType_Controller,
        kResourceType_Module,
        kResourceType_Language,
        kResourceType_CANPlugin,
        kResourceType_Accelerometer,
        kResourceType_ADXL345,
        kResourceType_AnalogChannel,
        kResourceType_AnalogTrigger,
        kResourceType_AnalogTriggerOutput,
        kResourceType_CANJaguar,
        kResourceType_Compressor,
        kResourceType_Counter,
        kResourceType_Dashboard,
        kResourceType_DigitalInput,
        kResourceType_DigitalOutput,
        kResourceType_DriverStationCIO,
        kResourceType_DriverStationEIO,
        kResourceType_DriverStationLCD,
        kResourceType_Encoder,
        kResourceType_GearTooth,
        kResourceType_Gyro,
        kResourceType_I2C,
        kResourceType_Framework,
        kResourceType_Jaguar,
        kResourceType_Joystick,
        kResourceType_Kinect,
        kResourceType_KinectStick,
        kResourceType_PIDController,
        kResourceType_Preferences,
        kResourceType_PWM,
        kResourceType_Relay,
        kResourceType_RobotDrive,
        kResourceType_SerialPort,
        kResourceType_Servo,
        kResourceType_Solenoid,
        kResourceType_SPI,
        kResourceType_Task,
        kResourceType_Ultrasonic,
        kResourceType_Victor,
        kResourceType_Button,
        kResourceType_Command,
        kResourceType_AxisCamera,
        kResourceType_PCVideoServer,
        kResourceType_SmartDashboard,
    } tResourceType;

    typedef enum
    {
        kLanguage_LabVIEW = 1,
        kLanguage_CPlusPlus = 2,
        kLanguage_Java = 3,
        kLanguage_Python = 4,

        kCANPlugin_BlackJagBridge = 1,
        kCANPlugin_2CAN = 2,

        kFramework_Iterative = 1,
        kFramework_Simple = 2,
    } tInstances;

    /**
     * Report the usage of a resource of interest.
     * 
     * @param resource one of the values in the tResourceType above (max value 51).
     * @param instanceNumber an index that identifies the resource instance.
     * @param context an optional additional context number for some cases (such as module number).  Set to 0 to omit.
     * @param feature a string to be included describing features in use on a specific resource.  Setting the same resource more than once allows you to change the feature string.
     */
    UINT32 report(tResourceType resource, UINT8 instanceNumber, UINT8 context = 0, const char *feature = NULL);
}

#ifdef __cplusplus
extern "C" {
#endif

    UINT32 FRC_NetworkCommunication_nUsageReporting_report(UINT8 resource, UINT8 instanceNumber, UINT8 context, const char *feature);

#ifdef __cplusplus
}
#endif

#endif // __UsageReporting_h__
