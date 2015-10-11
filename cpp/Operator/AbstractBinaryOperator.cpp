//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/AbstractOperator.h"
#include "../../include/Operator/AbstractBinaryOperator.h"
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
using namespace MathCompiler::Operator;

AbstractBinaryOperator::AbstractBinaryOperator(OperatorPriorityEnum priorityEnum
											   , CalculationDirectionEnum directionEnum
											   , const char* operatorStr
											  )
		: AbstractOperator(priorityEnum, directionEnum, operatorStr)
{ }

//
// Compile
//
const char* AbstractBinaryOperator::compile(const char* expression)
{
	string mathExpression(expression);
	unsigned long operatorIdx = mathExpression.find(getOperatorString());
	unsigned long operatorLen = strlen(getOperatorString());

	double left = atof(mathExpression.substr(0, operatorIdx).c_str());
	double right = atof(mathExpression.substr(operatorIdx + operatorLen, string::npos).c_str());

	double result = compile(left, right);

	stringstream ss;
	ss << result;
	return ss.str().c_str();
}