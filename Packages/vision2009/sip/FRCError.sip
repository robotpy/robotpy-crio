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
#include <Vision2009/FrcError.h>
%End

enum {
	ERR_VISION_GENERAL_ERROR		=166000,
	ERR_COLOR_NOT_FOUND			=166100,
	ERR_PARTICLE_TOO_SMALL			=166101,

	ERR_CAMERA_FAILURE			=166200,
	ERR_CAMERA_SOCKET_CREATE_FAILED		=166201,
	ERR_CAMERA_CONNECT_FAILED		=166202,
	ERR_CAMERA_STALE_IMAGE			=166203,
	ERR_CAMERA_NOT_INITIALIZED		=166204,
	ERR_CAMERA_NO_BUFFER_AVAILABLE		=166205,
	ERR_CAMERA_HEADER_ERROR			=166206,
	ERR_CAMERA_BLOCKING_TIMEOUT		=166207,
	ERR_CAMERA_AUTHORIZATION_FAILED		=166208,
	ERR_CAMERA_TASK_SPAWN_FAILED		=166209,
	ERR_CAMERA_TASK_INPUT_OUT_OF_RANGE	=166210,
	ERR_CAMERA_COMMAND_FAILURE		=166211
};

int GetLastVisionError();
const char* GetVisionErrorText(int errorCode);

