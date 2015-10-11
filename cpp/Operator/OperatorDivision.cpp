//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/OperatorDivision.h"
#include "../../include/Operator/AbstractBinaryOperator.h"

using namespace MathCompiler::Operator;

//
// Constructor
//
OperatorDivision::OperatorDivision()
		: AbstractBinaryOperator(OperatorPriorityEnum::DotOperator, CalculationDirectionEnum::Forward, "/")
{ }

//
// calculate
//
double OperatorDivision::compile(double left, double right)
{
	return left / right;
}