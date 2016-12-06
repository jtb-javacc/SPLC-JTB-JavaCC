/*
 * Interpreter.cpp
 *
 *  Created on: 7 mai 2014
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Interpreter.h"
#include "ParserConstants.h"
#include "Value.h"
using namespace std;
using namespace SPL;

Interpreter::Interpreter() {
}

Interpreter::~Interpreter() {
}
int Interpreter::count = 0;


int Interpreter::visit(AST::CompilationUnit<int>&n) {
	int ret = 0;
	cout << ">>> Interpreter::visit(CompilationUnit* n)" << endl;
	count += 1;
	// f0 -> ( %0 #0 VarDeclaration() #1 ";"
	// .. .. | %1 Statement() )*
	ret = n.f0->accept(*this);
	// f1 -> <EOF>
	ret = n.f1->accept(*this);
	int toto = n.f1->beginColumn;
	return ret;
}

int Interpreter::visit(AST::VarDeclaration<int>&n) {
	int ret = 0;
	cout << ">>> Interpreter::visit(VarDeclaration* n)" << endl;
	count += 1;
	// f0 -> ( %0 "boolean"
	// .. .. | %1 "int" )
    n.f0->accept(*this);
    // f1 -> <IDENTIFIER>
    n.f1->accept(*this);
	return ret;
}

int Interpreter::visit(AST::Statement<int>&n) {
	int ret = 0;
	cout << ">>> Interpreter::visit(Statement* n)" << endl;
	count += 1;
//    // f0 -> . %0 ";"
//    // .. .. | %1 LabeledStatement()
//    // .. .. | %2 Block()
//    // .. .. | %3 StatementExpression()
//    // .. .. | %4 IfStatement()
//    // .. .. | %5 WhileStatement()
//    // .. .. | %6 IOStatement()
//    n->f0->accept(this);
	return ret;
}
int Interpreter::visit(AST::NodeToken<int>&n) {
	int ret = 0;
#if	defined(USE_WCHAR_T)
	wchar_t * pEnd;
	wcout << ">>> Interpreter::visit( NodeToken* n)" << n.tokenImage << endl;
#else
	char * pEnd;
	cout << ">>> Interpreter::visit( NodeToken* n)" << n.tokenImage << endl;
#endif
	switch(n.kind) {
	case INTEGER_LITERAL:
#if	defined(USE_WCHAR_T)
		ret = wcstol(n.tokenImage.c_str(), &pEnd, 10);
#else
		ret = strtol(n.tokenImage.c_str(), &pEnd, 10);
#endif
		break;
	}
	count += 1;
	return ret;
}

