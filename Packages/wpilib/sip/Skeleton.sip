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

class Skeleton
{
%TypeHeaderCode
#include <WPILib/Skeleton.h>
%End

public:
	enum JointTypes {
		HipCenter = 0,
		Spine = 1,
		ShoulderCenter = 2,
		Head = 3,
		ShoulderLeft = 4,
		ElbowLeft = 5,
		WristLeft = 6,
		HandLeft = 7,
		ShoulderRight = 8,
		ElbowRight = 9,
		WristRight = 10,
		HandRight = 11,
		HipLeft = 12,
		KneeLeft = 13,
		AnkleLeft = 14,
		FootLeft = 15,
		HipRight = 16,
		KneeRight = 17,
		AnkleRight = 18,
		FootRight = 19,
		JointCount = 20
	};

	enum JointTrackingState { kNotTracked, kInferred, kTracked };

	struct Joint
	{
		float x;
		float y;
		float z;
		Skeleton::JointTrackingState trackingState;
	};

	Joint GetHandRight();
	Joint GetHandLeft();
	Joint GetWristRight();
	Joint GetWristLeft();
	Joint GetElbowLeft();
	Joint GetElbowRight();
	Joint GetShoulderLeft();
	Joint GetShoulderRight();
	Joint GetShoulderCenter();
	Joint GetHead();
	Joint GetSpine();
	Joint GetHipCenter();
	Joint GetHipRight();
	Joint GetHipLeft();
	Joint GetKneeLeft();
	Joint GetKneeRight();
	Joint GetAnkleLeft();
	Joint GetAnkleRight();
	Joint GetFootLeft();
	Joint GetFootRight();
	Joint GetJointValue(JointTypes index);
};
