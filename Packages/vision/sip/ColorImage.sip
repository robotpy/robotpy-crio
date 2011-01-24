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

class ColorImage : ImageBase
{
%TypeHeaderCode
#include <Vision/ColorImage.h>
%End
public:
	ColorImage(ImageType type);
	virtual ~ColorImage();
	BinaryImage *ThresholdRGB(int redLow, int redHigh, int greenLow, int greenHigh, int blueLow, int blueHigh) /Factory/;
	BinaryImage *ThresholdHSL(int hueLow, int hueHigh, int saturationLow, int saturationHigh, int luminenceLow, int luminenceHigh) /Factory/;
	BinaryImage *ThresholdHSV(int hueLow, int hueHigh, int saturationLow, int saturationHigh, int valueHigh, int valueLow) /Factory/;
	BinaryImage *ThresholdHSI(int hueLow, int hueHigh, int saturationLow, int saturationHigh, int intensityLow, int intensityHigh) /Factory/;
	BinaryImage *ThresholdRGB(Threshold &threshold) /Factory/;
	BinaryImage *ThresholdHSL(Threshold &threshold) /Factory/;
	BinaryImage *ThresholdHSV(Threshold &threshold) /Factory/;
	BinaryImage *ThresholdHSI(Threshold &threshold) /Factory/;
	MonoImage *GetRedPlane() /Factory/;
	MonoImage *GetGreenPlane() /Factory/;
	MonoImage *GetBluePlane() /Factory/;
	MonoImage *GetHSLHuePlane() /Factory/;
	MonoImage *GetHSVHuePlane() /Factory/;
	MonoImage *GetHSIHuePlane() /Factory/;
	MonoImage *GetLuminancePlane() /Factory/;
	MonoImage *GetValuePlane() /Factory/;
	MonoImage *GetIntensityPlane() /Factory/;
	void ReplaceRedPlane(MonoImage *plane);
	void ReplaceGreenPlane(MonoImage *plane);
	void ReplaceBluePlane(MonoImage *plane);
	void ReplaceHSLHuePlane(MonoImage *plane);
	void ReplaceHSVHuePlane(MonoImage *plane);
	void ReplaceHSIHuePlane(MonoImage *plane);
	void ReplaceHSLSaturationPlane(MonoImage *plane);
	void ReplaceHSVSaturationPlane(MonoImage *plane);
	void ReplaceHSISaturationPlane(MonoImage *plane);
	void ReplaceLuminancePlane(MonoImage *plane);
	void ReplaceValuePlane(MonoImage *plane);
	void ReplaceIntensityPlane(MonoImage *plane);
	void ColorEqualize();
	void LuminanceEqualize();
};
