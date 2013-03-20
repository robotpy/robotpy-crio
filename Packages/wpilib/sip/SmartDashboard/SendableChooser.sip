// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2013 Peter Johnson
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

class SendableChooser : Sendable
{
%TypeHeaderCode
#include <WPILib/SmartDashboard/SendableChooser.h>
%End

%TypeCode
    typedef std::map<std::string, PyObject *> ChoiceMap;
    ChoiceMap m_data;
%End

public:
	SendableChooser();
	virtual ~SendableChooser();
    %MethodCode
        const ChoiceMap::iterator end = m_data.end();
        for (ChoiceMap::iterator i = m_data.begin(); i != end; ++i)
            Py_DECREF(i->second);
        m_data.clear();
    %End

	void AddObject(const char *name, PyObject *object);
    %MethodCode
        ChoiceMap::iterator i = m_data.find(a0);
        if (i != m_data.end())
        {
            Py_DECREF(i->second);
            m_data.erase(i);
        }
        
        Py_INCREF(a1);
        m_data[a0] = a1;
        
        sipCpp->AddObject(a0, a1);
    %End
    
	void AddDefault(const char *name, PyObject *object);
    %MethodCode
        ChoiceMap::iterator i = m_data.find(a0);
        if (i != m_data.end())
        {
            Py_DECREF(i->second);
            m_data.erase(i);
        }
        
        Py_INCREF(a1);
        m_data[a0] = a1;
        
        sipCpp->AddDefault(a0, a1);
    %End
    
	PyObject *GetSelected();
    %MethodCode
        sipRes = (PyObject*)sipCpp->GetSelected();
        if (sipRes == NULL)
            sipRes = Py_None;
        Py_INCREF(sipRes);
    %End

	virtual void InitTable(ITable* subtable);
	virtual ITable* GetTable();
	virtual std::string GetSmartDashboardType();
};
