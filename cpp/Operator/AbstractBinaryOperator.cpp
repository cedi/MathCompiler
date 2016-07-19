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
											   , const string& operatorStr
											  )
		: AbstractOperator(priorityEnum, directionEnum, operatorStr)
{ }

//
// Compile
//
string AbstractBinaryOperator::compile(const string& expression)
{
	unsigned long operatorIdx = expression.find(getOperatorString());
	unsigned long operatorLen = getOperatorString().length();

	double left = atof(expression.substr(0, operatorIdx).c_str());
	double right = atof(expression.substr(operatorIdx + operatorLen, string::npos).c_str());

	double result = compile(left, right);

	stringstream ss;
	ss << result;
	return ss.str();
}