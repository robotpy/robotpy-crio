PROJECT_TARGET = _vision.pyd
PROJECT_OBJECTS = sip_visioncmodule.o
PROJECT_OBJECTS += sip_visionAxisCamera.o
PROJECT_OBJECTS += sip_visionAxisCameraParams.o
PROJECT_OBJECTS += sip_visionBinaryImage.o
PROJECT_OBJECTS += sip_visionColorImage.o
PROJECT_OBJECTS += sip_visionHSLImage.o
PROJECT_OBJECTS += sip_visionImageBase.o
PROJECT_OBJECTS += sip_visionMonoImage.o
PROJECT_OBJECTS += sip_visionPCVideoServer.o
PROJECT_OBJECTS += sip_visionRGBImage.o
PROJECT_OBJECTS += sip_visionstdvector0100EllipseMatch.o
PROJECT_OBJECTS += sip_visionstdvector0100ParticleAnalysisReport.o
PROJECT_OBJECTS += sip_visionstdvector1800.o
PROJECT_OBJECTS += sip_visionstdvector2400.o
PROJECT_OBJECTS += sip_visionThreshold.o

PROJECT_OBJECTS += Vision/AxisCamera.o
PROJECT_OBJECTS += Vision/AxisCameraParams.o
PROJECT_OBJECTS += Vision/BinaryImage.o
PROJECT_OBJECTS += Vision/ColorImage.o
PROJECT_OBJECTS += Vision/EnumCameraParameter.o
PROJECT_OBJECTS += Vision/HSLImage.o
PROJECT_OBJECTS += Vision/ImageBase.o
PROJECT_OBJECTS += Vision/IntCameraParameter.o
PROJECT_OBJECTS += Vision/MonoImage.o
PROJECT_OBJECTS += Vision/PCVideoServer.o
PROJECT_OBJECTS += Vision/RGBImage.o
PROJECT_OBJECTS += Vision/Threshold.o

ADDED_INCLUDES = -I../sip -I. -I../vision2009 -I../wpilib -I../wpilib/WPILib -I../wpilib/WPILib/CInterfaces
ADDED_CFLAGS = -D'SVN_REV="2242"'
ADDED_C++FLAGS = -D'SVN_REV="2242"'

dist ::
	cp *.py $(DISTDIR)/

include ../../mk/module.mk

dist ::
	cp *.py $(DISTDIR)/
