//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/Operator/OperatorPlus.h"
#include "../../include/Operator/AbstractBinaryOperator.h"
#include "../../include/OperatorEnum.h"

using namespace MathCompiler::Operator;

//
// Constructor
//
OperatorPlus::OperatorPlus()
		: AbstractBinaryOperator(OperatorPriorityEnum::LineOperator, CalculationDirectionEnum::Forward, "+")
{ }

//
// calculate
//
double OperatorPlus::compile(double left, double right)
{
	return left + right;
}
