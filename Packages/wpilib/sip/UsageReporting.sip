// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2012 Peter Johnson
// 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

%ModuleHeaderCode
#include <WPILib/NetworkCommunication/UsageReporting.h>
%End

namespace nUsageReporting
{
    enum tResourceType
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
    };

    enum tInstances
    {
        kLanguage_LabVIEW = 1,
        kLanguage_CPlusPlus = 2,
        kLanguage_Java = 3,
        kLanguage_Python = 4,

        kCANPlugin_BlackJagBridge = 1,
        kCANPlugin_2CAN = 2,

        kFramework_Iterative = 1,
        kFramework_Simple = 2,
    };

    uint32_t report(nUsageReporting::tResourceType resource, uint8_t instanceNumber, uint8_t context = 0, const char *feature = NULL);
};

uint32_t FRC_NetworkCommunication_nUsageReporting_report(uint8_t resource, uint8_t instanceNumber, uint8_t context, const char *feature);
