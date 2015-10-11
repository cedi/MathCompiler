//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/OperatorMinus.h"
#include "../../include/Operator/AbstractBinaryOperator.h"
#include "../../include/OperatorEnum.h"

using namespace MathCompiler::Operator;

//
// Constructor
//
OperatorMinus::OperatorMinus()
		: AbstractBinaryOperator(OperatorPriorityEnum::DotOperator, CalculationDirectionEnum::Forward, "-")
{ }

//
// calculate
//
double OperatorMinus::compile(double left, double right)
{
	return left - right;
}