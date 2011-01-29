// This file is part of the RobotPy vision package.
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
#include <Vision/AxisCamera.h>
%End

class AxisCamera: AxisCameraParams
{
%TypeHeaderCode
#include <Vision/AxisCamera.h>
%End
public:
	virtual ~AxisCamera();
	static AxisCamera& GetInstance();
	void DeleteInstance();

	bool IsFreshImage();
	SEM_ID GetNewImageSem();

	int GetImage(Image *imaqImage);
	int GetImage(ColorImage *image);
	HSLImage *GetImage() /Factory/;

	//TODO:int CopyJPEG(char **destImage, int &destImageSize, int &destImageBufferSize);
private:
	AxisCamera(const AxisCamera&);
	AxisCamera(const char *cameraIP);
};

void AxisCameraStart();
int AxisCameraGetImage(Image *image);
void AxisCameraDeleteInstance();
int AxisCameraFreshImage();

void AxisCameraWriteBrightness(int brightness);
int AxisCameraGetBrightness();
void AxisCameraWriteWhiteBalance(AxisCameraParams::WhiteBalance_t whiteBalance);
AxisCameraParams::WhiteBalance_t AxisCameraGetWhiteBalance();
void AxisCameraWriteColorLevel(int colorLevel);
int AxisCameraGetColorLevel();
void AxisCameraWriteExposureControl(AxisCameraParams::Exposure_t exposure);
AxisCameraParams::Exposure_t AxisCameraGetExposureControl();
void AxisCameraWriteExposurePriority(int exposurePriority);
int AxisCameraGetExposurePriority();
void AxisCameraWriteMaxFPS(int maxFPS);
int AxisCameraGetMaxFPS();

void AxisCameraWriteResolution(AxisCameraParams::Resolution_t resolution);
AxisCameraParams::Resolution_t AxisCameraGetResolution();
void AxisCameraWriteCompression(int compression);
int AxisCameraGetCompression();
void AxisCameraWriteRotation(AxisCameraParams::Rotation_t rotation);
AxisCameraParams::Rotation_t AxisCameraGetRotation();
