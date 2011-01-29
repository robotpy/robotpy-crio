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
#include <Vision2009/VisionAPI.h>
%End

enum { DEFAULT_BORDER_SIZE = 3, DEFAULT_SATURATION_THRESHOLD = 40 };

struct ParticleAnalysisReport {
%TypeHeaderCode
#include <Vision2009/VisionAPI.h>
%End
	int 	imageHeight;
	int 	imageWidth;
	double 	imageTimestamp;				
	int	particleIndex;
	int 	center_mass_x;
	int 	center_mass_y;
	double 	center_mass_x_normalized;
	double 	center_mass_y_normalized;
	double 	particleArea;
	Rect 	boundingRect;
	double 	particleToImagePercent;
	double 	particleQuality;
};

struct ColorReport {
%TypeHeaderCode
#include <Vision2009/VisionAPI.h>
%End
	int	numberParticlesFound;
	int 	largestParticleNumber;
	float 	particleHueMax;
	float 	particleHueMin;
	float 	particleHueMean;
	float 	particleSatMax;
	float 	particleSatMin;
	float 	particleSatMean;
	float 	particleLumMax;
	float 	particleLumMin;
	float 	particleLumMean;
};

Image* frcCreateImage( ImageType type ) /Factory/;

int frcCopyImage( Image* dest, const Image* source );

int frcCrop( Image* dest, const Image* source, Rect rect );

int frcScale(Image* dest, const Image* source, int xScale, int yScale, ScalingMode scaleMode );

int frcReadImage( Image* image, const char* fileName );
int frcWriteImage( const Image* image, const char* fileName);

HistogramReport* frcHistogram( const Image* image, int numClasses, float min, float max, Rect rect );
ColorHistogramReport* frcColorHistogram(const Image* image, int numClasses, ColorMode mode, Image* mask);

int frcGetPixelValue( const Image* image, Point pixel, PixelValue* value /Out/);

int frcParticleFilter(Image* dest, Image* source, const ParticleFilterCriteria2* criteria /Array/, 
		int criteriaCount /ArraySize/, const ParticleFilterOptions* options, Rect rect, int* numParticles /Out/);
int frcParticleFilter(Image* dest, Image* source, const ParticleFilterCriteria2* criteria /Array/, 
		int criteriaCount /ArraySize/, const ParticleFilterOptions* options, int* numParticles /Out/);
int frcMorphology(Image* dest, Image* source, MorphologyMethod method);
int frcMorphology(Image* dest, Image* source, MorphologyMethod method, const StructuringElement* structuringElement);
int frcRejectBorder(Image* dest, Image* source);
int frcRejectBorder(Image* dest, Image* source, int connectivity8);
int frcCountParticles(Image* image, int* numParticles);
int frcParticleAnalysis(Image* image, int particleNumber, ParticleAnalysisReport* par);

int frcEqualize(Image* dest, const Image* source, float min, float max);
int frcEqualize(Image* dest, const Image* source, float min, float max, const Image* mask);

int frcColorEqualize(Image* dest, const Image* source);
int frcColorEqualize(Image* dest, const Image* source, int colorEqualization);

int frcSmartThreshold(Image* dest, const Image* source, unsigned int windowWidth, unsigned int windowHeight, 
		LocalThresholdMethod method, double deviationWeight, ObjectType type);
int frcSmartThreshold(Image* dest, const Image* source, unsigned int windowWidth, unsigned int windowHeight, 
		LocalThresholdMethod method, double deviationWeight, ObjectType type, float replaceValue);

int frcSimpleThreshold(Image* dest, const Image* source, float rangeMin, float rangeMax, float newValue);
int frcSimpleThreshold(Image* dest, const Image* source, float rangeMin, float rangeMax);

int frcColorThreshold(Image* dest, const Image* source, ColorMode mode, 
		const Range* plane1Range, const Range* plane2Range, const Range* plane3Range);
int frcColorThreshold(Image* dest, const Image* source, int replaceValue, ColorMode mode, 
		const Range* plane1Range, const Range* plane2Range, const Range* plane3Range);
int frcHueThreshold(Image* dest, const Image* source, const Range* hueRange);
int frcHueThreshold(Image* dest, const Image* source, const Range* hueRange, int minSaturation);

int frcExtractColorPlanes(const Image* image, ColorMode mode, Image* plane1, Image* plane2, Image* plane3);
int frcExtractHuePlane(const Image* image, Image* huePlane);
int frcExtractHuePlane(const Image* image, Image* huePlane, int minSaturation);

