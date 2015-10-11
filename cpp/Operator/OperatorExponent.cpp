//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/OperatorExponent.h"
#include "../../include/Operator/AbstractBinaryOperator.h"
#include <cmath>

using namespace MathCompiler::Operator;

//
// Constructor
//
OperatorExponent::OperatorExponent()
		: AbstractBinaryOperator(OperatorPriorityEnum::Exponent, CalculationDirectionEnum::Backward, "^")
{ }

//
// calculate
//
double OperatorExponent::compile(double left, double right)
{
	return pow(left, right);
}