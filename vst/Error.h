/*
 * Error.h
 *
 *  Created on: 17 mai 2014
 *      Author: FrancisANDRE
 */

#ifndef ERROR_H_
#define ERROR_H_
#include <string>
using namespace std;

class Error {
public:
	Error(const string& message);
	virtual ~Error();
};

#endif /* ERROR_H_ */
