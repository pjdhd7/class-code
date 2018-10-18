#ifndef PROGPARSER_H
#define PROGPARSER_H

#include <iostream>
#include <sstream>
#include "mylexer.h"

using namespace std;

extern bool is_correct;
const int limit = 200;

//FunctionDeclaration { FunctionDeclaration }
void FunctionSequence(istringstream& ss, char* input, string& temp);

//FUNC identifier ( [ ParamSequence ] ) BEGIN StatementSequence END.
void FunctionDeclaration(istringstream& ss, char* input, string& temp);

//identifier  { , identifier }
void ParamSequence(istringstream& ss, char* input, string& temp);

//Statement { Statement }
void StatementSequence(istringstream& ss, char* input, string& temp);

//Assignment | PrintStatement | RetStatement | IfStatement | LoopStatement
void Statement(istringstream& ss, char* input, string& temp);

//LOOP ( Expression ) StatementSequence POOL
void LoopStatement(istringstream& ss, char* input, string& temp);

//IF ( Expression ) StatementSequence [ ELSE StatementSequence ] FI
void IfStatement(istringstream& ss, char* input, string& temp);

//RET identifier !
void RetStatement(istringstream& ss, char* input, string& temp);

//PRINT ( Expression )!
void PrintStatement(istringstream& ss, char* input, string& temp);

//identifier := Expression !
void Assignment(istringstream& ss, char* input, string& temp);

//integer | decimal | string | identifier | ( Expression ) | ~ Factor
void Factor(istringstream& ss, char* input, string& temp);

//Factor { MulOperator Factor }
void Term(istringstream& ss, char* input, string& temp);

//Term { AddOperator Term }
void SimpleExpression(istringstream& ss, char* input, string& temp);

//SimpleExpression [ Relation SimpleExpression ]
void Expression(istringstream& ss, char* input, string& temp);

#endif