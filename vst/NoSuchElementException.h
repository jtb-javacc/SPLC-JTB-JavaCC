/*
 * NoSuchElementException.h
 *
 *  Created on: 16 mai 2014
 *      Author: FrancisANDRE
 */

#ifndef NOSUCHELEMENTEXCEPTION_H_
#define NOSUCHELEMENTEXCEPTION_H_
#include <string>
#include <exception>
using namespace std;

class NoSuchElementException : public exception {
public:
	NoSuchElementException(const string& message);
	virtual ~NoSuchElementException();
};

#endif /* NOSUCHELEMENTEXCEPTION_H_ */
