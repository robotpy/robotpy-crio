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
#include <Vision2009/TrackAPI.h>
%End

struct TrackingThreshold {
%TypeHeaderCode
#include <Vision2009/TrackAPI.h>
%End
	char *name
	{
	%GetCode
		size_t len = 0;
		while (len < 64 && sipCpp->name[len] != '\0')
			++len;
		sipPy = PyUnicode_FromStringAndSize(sipCpp->name, len);
	%End
	%SetCode
		if (sipPy == Py_None) {
			sipCpp->name[0] = '\0';
		}
		else if (PyUnicode_Check(sipPy)) {
			PyObject* s = PyUnicode_AsEncodedString(sipPy, "UTF-8", "");
			if (!s)
				sipErr = 1;
			else {
				strncpy(sipCpp->name, PyBytes_AS_STRING(s), 64);
				Py_DECREF(s);
			}
		}
		else {
			PyErr_SetString(PyExc_ValueError, "name must be a string");
			sipErr = 1;
		}
	%End
	};
	//TODO: char name[64];
	Range hue;
	Range saturation;
	Range luminance;
};
		
enum FrcHue { 
	RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, WHITE, PINK
};

enum FrcLight { 
	PASSIVE_LIGHT, BRIGHT_LIGHT, ACTIVE_LIGHT, WHITE_LIGHT, FLUORESCENT
};

TrackingThreshold GetTrackingData(FrcHue hue, FrcLight light);

void PrintReport(ParticleAnalysisReport* myReport);
void PrintReport(ColorReport* myReport);
void PrintReport(TrackingThreshold* myReport);

int GetLargestParticle(Image* binaryImage, int* particleNum /Out/);
int GetLargestParticle(Image* binaryImage, int* particleNum /Out/, Rect rect);
int FindColor(FrcHue color, ParticleAnalysisReport* trackReport);
int FindColor(const Range* hueRange, ParticleAnalysisReport *trackReport);
int FindColor(const Range* hueRange, int minSaturation, ParticleAnalysisReport *trackReport);
int FindColor(ColorMode mode, const Range* plane1Range, const Range* plane2Range, 
		const Range* plane3Range, ParticleAnalysisReport *trackReport);
int FindColor(ColorMode mode, const Range* plane1Range, const Range* plane2Range, 
		const Range* plane3Range, ParticleAnalysisReport *trackReport, ColorReport *colorReport);
int FindColor(ColorMode mode, const Range* plane1Range, const Range* plane2Range, 
		const Range* plane3Range, ParticleAnalysisReport *trackReport, 
		ColorReport *colorReport, Rect rect);

