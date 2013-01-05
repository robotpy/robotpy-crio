/*
 * EOFException.h
 *
 *  Created on: Oct 1, 2012
 *      Author: Mitchell Wills
 */

#ifndef EOFEXCEPTION_H_
#define EOFEXCEPTION_H_

class EOFException;

#include "IOException.h"



class EOFException : public IOException{
public:
	EOFException();
	virtual ~EOFException() throw ();
	virtual bool isEOF();
};




#endif /* EOFEXCEPTION_H_ */
