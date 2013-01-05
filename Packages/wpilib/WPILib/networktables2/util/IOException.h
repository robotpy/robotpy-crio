/*
 * IOException.h
 *
 *  Created on: Oct 1, 2012
 *      Author: Mitchell Wills
 */

#ifndef IOEXCEPTION_H_
#define IOEXCEPTION_H_


class IOException;


#include <exception>




class IOException : public std::exception{
public:
	IOException(const char* message);
	IOException(const char* message, int errorValue);
	const char* what();
	virtual bool isEOF();
	virtual ~IOException() throw ();
private:
	const char* message;
	int errorValue;
};


#endif /* IOEXCEPTION_H_ */
