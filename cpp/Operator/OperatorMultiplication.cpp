//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/OperatorMultiplication.h"
#include "../../include/Operator/AbstractBinaryOperator.h"

using namespace MathCompiler::Operator;

//
// Constructor
//
OperatorMultiplication::OperatorMultiplication()
		: AbstractBinaryOperator(OperatorPriorityEnum::DotOperator, CalculationDirectionEnum::Forward, "*")
{ }

//
// calculate
//
double OperatorMultiplication::compile(double left, double right)
{
	return left * right;
}