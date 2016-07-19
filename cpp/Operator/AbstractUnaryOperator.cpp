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
											 , const string& operatorStr
											 , bool operatorRightOfNumber
											)
		: AbstractOperator(priorityEnum, directionEnum, operatorStr)
		  , operatorRightOfNumber(operatorRightOfNumber)
{ }

//
// Compile
//
string AbstractUnaryOperator::compile(const string& expression)
{
	unsigned long operatorIdx = expression.find(getOperatorString());
	unsigned long operatorLen = getOperatorString().length();

	double number = 0;

	if(operatorRightOfNumber)
	{
		number = atof(expression.substr(operatorIdx + operatorLen, string::npos).c_str());
	}
	else
	{
		number = atof(expression.substr(0, operatorIdx).c_str());
	}

	double result = compile(number);

	stringstream ss;
	ss << result;
	return ss.str();
}