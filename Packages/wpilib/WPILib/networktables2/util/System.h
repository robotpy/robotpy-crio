/*
 * System.h
 * 
 * For some platform specific code related to the system
 *
 *  Created on: Sep 25, 2012
 *      Author: Mitchell Wills
 */

#ifndef TIME_H_
#define TIME_H_

void sleep_ms(unsigned long ms);
unsigned long currentTimeMillis();
void writeWarning(const char* message);


#endif /* TIME_H_ */
