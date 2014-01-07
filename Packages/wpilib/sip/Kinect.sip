// This file is part of the RobotPy wpilib package.
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

class Kinect : ErrorBase
{
%TypeHeaderCode
#include <WPILib/Kinect.h>
%End

public:
	enum SkeletonTrackingState {kNotTracked, kPositionOnly, kTracked};
	enum SkeletonQuality {kClippedRight = 1, kClippedLeft = 2, kClippedTop = 4, kClippedBottom = 8};
	struct Point4 {
		float x;
		float y;
		float z;
		float w;
	};

	int GetNumberOfPlayers();
	Point4 GetFloorClipPlane();
	Point4 GetGravityNormal();
	Skeleton GetSkeleton(int skeletonIndex = 1);
	Point4 GetPosition(int skeletonIndex = 1);
	uint32_t GetQuality(int skeletonIndex = 1);
	SkeletonTrackingState GetTrackingState(int skeletonIndex = 1);

	static Kinect *GetInstance();

private:
	Kinect();
	~Kinect();
	Kinect(const Kinect&);
};
