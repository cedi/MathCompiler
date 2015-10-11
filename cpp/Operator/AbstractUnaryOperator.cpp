//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/AbstractOperator.h"
#include "../../include/Operator/AbstractUnaryOperator.h"
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
using namespace MathCompiler::Operator;

AbstractUnaryOperator::AbstractUnaryOperator(OperatorPriorityEnum priorityEnum
											 , CalculationDirectionEnum directionEnum
											 , const char* operatorStr
											 , bool operatorRightOfNumber
											)
		: AbstractOperator(priorityEnum, directionEnum, operatorStr)
		  , operatorRightOfNumber(operatorRightOfNumber)
{ }

//
// Compile
//
const char* AbstractUnaryOperator::compile(const char* expression)
{
	string mathExpression(expression);
	unsigned long operatorIdx = mathExpression.find(getOperatorString());
	unsigned long operatorLen = strlen(getOperatorString());

	double number = 0;

	if(operatorRightOfNumber)
	{
		number = atof(mathExpression.substr(operatorIdx + operatorLen, string::npos).c_str());
	}
	else
	{
		number = atof(mathExpression.substr(0, operatorIdx).c_str());
	}

	double result = compile(number);

	stringstream ss;
	ss << result;
	return ss.str().c_str();
}