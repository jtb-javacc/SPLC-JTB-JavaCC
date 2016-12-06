/*
 * Interpreter.h
 *
 *  Created on: 7 mai 2014
 *      Author: FrancisANDRE
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "DepthFirstRetArguVisitor.h"
class Value;

class Interpreter : public DepthFirstRetArguVisitor<int> {
public:
	static int count;

public:
	Interpreter();
	virtual ~Interpreter();

	int visit(AST::NodeToken<int>&n);
	int visit(AST::CompilationUnit<int>&n);
	int visit(AST::VarDeclaration<int>&n);
	int visit(AST::Statement<int>&n);
};

#endif /* INTERPRETER_H_ */
