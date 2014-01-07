// This file is part of the RobotPy vision2009 package.
//
// Copyright (c) 2011 Peter Johnson
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

%ModuleCode
#include <Vision2009/AxisCamera.h>
%End

enum { CAMERA_PORT=80, CAMERA_IMAGE_STALE_TIME_SEC=2 };

enum FrcvCameraMetric {CAM_STARTS, CAM_STOPS, 
	CAM_NUM_IMAGE, CAM_BUFFERS_WRITTEN, CAM_BLOCKING_COUNT,
	
	CAM_SOCKET_OPEN, CAM_SOCKET_INIT_ATTEMPTS, CAM_BLOCKING_TIMEOUT,
	CAM_GETIMAGE_SUCCESS, CAM_GETIMAGE_FAILURE, 
	
	CAM_STALE_IMAGE, CAM_GETIMAGE_BEFORE_INIT, CAM_GETIMAGE_BEFORE_AVAILABLE,
	CAM_READ_JPEG_FAILURE, CAM_PID_SIGNAL_ERR, 
	
	CAM_BAD_IMAGE_SIZE, CAM_HEADER_ERROR};

enum { CAM_NUM_METRICS=17 };

int Priv_SetWriteFileAllowed(uint32_t enable);

enum ImageResolution { k640x480, k320x240, k160x120 };
enum ImageRotation { ROT_0 = 0, ROT_180 = 180 };

int StartCameraTask();

int GetImage(Image* cameraImage, double *timestamp /Out/);
int GetImageBlocking(Image* cameraImage, double *timestamp /Out/, double lastImageTimestamp);
int GetImageData(char** imageData, int* numBytes, double* currentImageTimestamp /Out/);
int GetImageDataBlocking(char** imageData, int* numBytes, double* timestamp /Out/, double lastImageTimestamp);

void StartImageAcquisition();
void StopImageAcquisition();
void StartImageSignal(int taskId);

int GetCameraMetric(FrcvCameraMetric metric);

int ConfigureCamera(char *configString);
int GetCameraSetting(char *configString, char *cameraResponse);
int GetImageSetting(char *configString, char *cameraResponse);

int StartCameraTask(int frames, int compression, ImageResolution resolution, ImageRotation rotation);
int StopCameraTask();

