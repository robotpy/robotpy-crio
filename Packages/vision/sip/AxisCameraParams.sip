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

class AxisCameraParams : ErrorBase
{
%TypeHeaderCode
#include <Vision/AxisCameraParams.h>
%End
public:
	enum Exposure_t {kExposure_Automatic, kExposure_Hold, kExposure_FlickerFree50Hz, kExposure_FlickerFree60Hz};
	enum WhiteBalance_t {kWhiteBalance_Automatic, kWhiteBalance_Hold, kWhiteBalance_FixedOutdoor1, kWhiteBalance_FixedOutdoor2, kWhiteBalance_FixedIndoor, kWhiteBalance_FixedFlourescent1, kWhiteBalance_FixedFlourescent2};
	enum Resolution_t {kResolution_640x480, kResolution_640x360, kResolution_320x240, kResolution_160x120};
	enum Rotation_t {kRotation_0, kRotation_180};

protected:
	AxisCameraParams(const char* ipAddress);
	virtual ~AxisCameraParams();

public:
	void WriteBrightness(int);
	int GetBrightness();
	void WriteWhiteBalance(WhiteBalance_t whiteBalance);
	WhiteBalance_t GetWhiteBalance();
	void WriteColorLevel(int);
	int GetColorLevel();
	void WriteExposureControl(Exposure_t);
	Exposure_t GetExposureControl();
	void WriteExposurePriority(int);
	int GetExposurePriority();
	void WriteMaxFPS(int);
	int GetMaxFPS();

	void WriteResolution(Resolution_t);
	Resolution_t GetResolution();
	void WriteCompression(int);
	int GetCompression();
	void WriteRotation(Rotation_t);
	Rotation_t GetRotation();

protected:
	virtual void RestartCameraTask() = 0;
	int CreateCameraSocket(const char *requestString);

	static int s_ParamTaskFunction(AxisCameraParams* thisPtr);
	int ParamTaskFunction();

	int UpdateCamParam(const char *param);
	int ReadCamParams();
};
