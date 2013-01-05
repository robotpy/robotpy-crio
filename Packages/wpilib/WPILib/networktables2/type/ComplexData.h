/*
 * ComplexData.h
 *
 *  Created on: Sep 24, 2012
 *      Author: Mitchell Wills
 */

#ifndef COMPLEXDATA_H_
#define COMPLEXDATA_H_


class ComplexData;


//#include "ComplexEntryType.h" can't do this cause it causes order of definition issues
class ComplexEntryType;


class ComplexData{
	/**
	 *
	 * @author Mitchell
	 */
private:
	ComplexEntryType& type;
public:
	ComplexData(ComplexEntryType& type);
	    
	ComplexEntryType& GetType();

};


#endif /* COMPLEXDATA_H_ */
