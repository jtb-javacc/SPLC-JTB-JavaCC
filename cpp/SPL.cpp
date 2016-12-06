/*
 * Main.cpp

 *
 *  Created on: 7 mai 2014
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <streambuf>
#include <fstream>
#include "CompilationUnit.h"
#include "Statement.h"
#include "VarDeclaration.h"
#include "Value.h"
#include "Token.h"
#include "Foo.h"
#include "Interpreter.h"
//#include "InterpreterR.h"
#include "NodeToken.h"
#include "Parser.h"
#include "TreeDumper.h"

#define NL "\n"
using namespace SPL;
using namespace AST;
using namespace std;
JAVACC_STRING_TYPE readFileFully(char *file_name) {
	JAVACC_STRING_TYPE s;
#if WIDE_CHAR
	wifstream in;
#else
	ifstream in;
#endif
	in.open(file_name, ios::in);
	// Very inefficient.
	while (!in.eof()) {
		s += in.get();
	}
	return s;
//	s += "int n;"; s+= NL;
//	s += "int fact;"; s+= NL;
//	s += "read n;"; s+= NL;
//	s += "fact = 1;"; s+= NL;
//	s += "while (n > 1)"; s+= NL;
//	s += "{"; s+= NL;
//	s += "   fact = fact * n;"; s+= NL;
//	s += "n = n - 1;"; s+= NL;
//	s += "}"; s+= NL;
//	s += "write fact;"; s+= NL;
//
//	return "int fact;\n";
}
template AST::CompilationUnit<int>* Parser::CompilationUnit<int>();


int main(int argc, char** argv) {
	{
//		NodeToken<Value*>* nt1;
//		NodeToken<Value*>* nt2;
//		nt1 = new NodeToken<Value*>("foo");
//		nt2 = new NodeToken<Value*>("bar");
//		VarDeclaration<Value*>* v = new VarDeclaration<Value*>();
//		Statement<Value*>* s = new Statement<Value*>(nt1, nt2);
//		CompilationUnit<Value*> cu(v, s);
//
//
//		InterpreterR interpreterR;
//		interpreterR.visit(cu);
//		cout << "count = " << interpreterR.count << endl;
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	JAVACC_STRING_TYPE s = readFileFully(argv[1]);
	{
		CharStream *stream = new CharStream(s.c_str(), s.size() - 1, 1, 1);
		ParserTokenManager *scanner = new ParserTokenManager(stream);

		Parser parser(scanner);

		if (true) {
			CompilationUnit<int>* cup;
			cup = parser.CompilationUnit<int>();
			IRetArguVisitor<int>* dumper = new TreeDumper<int>(cout);
			dumper->visit(*cup);
		} else {
			int foo = 0;
			CompilationUnit<int>* cup;
			cup = parser.CompilationUnit<int>();
			Interpreter interpreter;
			interpreter.visit(*cup);
			cout << "count = " << interpreter.count << endl;
			cout.flush();
		}
	}
	return 0;
}

#if 0
namespace AST {
template class INode<Value*, int>;
template class INodeList<Value*, int>;
template class NodeChoice<Value*, int>;
template class NodeList<Value*, int>;
template class NodeListOptional<Value*, int>;
template class NodeSequence<Value*, int>;
template class NodeOptional<Value*, int>;
template class NodeTCF<Value*, int>;
template class NodeToken<Value*, int>;

template class CompilationUnit<Value*, int>;
template class VarDeclaration<Value*, int>;
template class Expression<Value*, int>;
template class Assignment<Value*, int>;
template class ConditionalOrExpression<Value*, int>;
template class ConditionalAndExpression<Value*, int>;
template class InclusiveOrExpression<Value*, int>;
template class ExclusiveOrExpression<Value*, int>;
template class AndExpression<Value*, int>;
template class EqualityExpression<Value*, int>;
template class RelationalExpression<Value*, int>;
template class AdditiveExpression<Value*, int>;
template class MultiplicativeExpression<Value*, int>;
template class UnaryExpression<Value*, int>;
template class PrimaryExpression<Value*, int>;
template class Id<Value*, int>;
template class Literal<Value*, int>;
template class BooleanLiteral<Value*, int>;
template class Statement<Value*, int>;
template class LabeledStatement<Value*, int>;
template class Block<Value*, int>;
template class StatementExpression<Value*, int>;
template class IfStatement<Value*, int>;
template class WhileStatement<Value*, int>;
template class IOStatement<Value*, int>;
template class ReadStatement<Value*, int>;
template class WriteStatement<Value*, int>;
}
namespace AST {
template class INode<int>;
template class INodeList<int>;
template class NodeChoice<int>;
template class NodeList<int>;
template class NodeListOptional<int>;
template class NodeSequence<int>;
template class NodeOptional<int>;
template class NodeTCF<int>;
template class NodeToken<int>;

template class CompilationUnit<int>;
template class VarDeclaration<int>;
template class Expression<int>;
template class Assignment<int>;
template class ConditionalOrExpression<int>;
template class ConditionalAndExpression<int>;
template class InclusiveOrExpression<int>;
template class ExclusiveOrExpression<int>;
template class AndExpression<int>;
template class EqualityExpression<int>;
template class RelationalExpression<int>;
template class AdditiveExpression<int>;
template class MultiplicativeExpression<int>;
template class UnaryExpression<int>;
template class PrimaryExpression<int>;
template class Id<int>;
template class Literal<int>;
template class BooleanLiteral<int>;
template class Statement<int>;
template class LabeledStatement<int>;
template class Block<int>;
template class StatementExpression<int>;
template class IfStatement<int>;
template class WhileStatement<int>;
template class IOStatement<int>;
template class ReadStatement<int>;
template class WriteStatement<int>;
}
#endif

