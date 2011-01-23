//
//  visionmod.sip - SIP bindings for wpilib vision library
//  This file is part of RobotPy.
//

%Module _vision

%Copying
Copyright (c) 2011 Peter Johnson

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
%End

%DefaultEncoding "UTF-8"

%Import ../wpilib/sip/wpilibmod.sip
%Import ../vision2009/sip/vision2009mod.sip
%Import ../nivision/sip/nivisionmod.sip
%Include ../sip/stdvector.sip

%Include AxisCamera.sip
%Include AxisCameraParams.sip
%Include BinaryImage.sip
%Include ColorImage.sip
%Include HSLImage.sip
%Include ImageBase.sip
%Include MonoImage.sip
%Include PCVideoServer.sip
%Include RGBImage.sip
%Include Threshold.sip
