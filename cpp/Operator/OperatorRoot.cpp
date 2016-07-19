//
// Created by Cedric Kienzler on 11.10.15.
//

#include <cmath>
#include "../../include/Operator/OperatorRoot.h"
#include "../../include/Operator/AbstractBinaryOperator.h"
#include "../../include/OperatorEnum.h"

using namespace MathCompiler::Operator;

//
// Constructor
//
OperatorRoot::OperatorRoot()
		: AbstractBinaryOperator(OperatorPriorityEnum::Function, CalculationDirectionEnum::Forward, "root")
{ }

//
// calculate
//
double OperatorRoot::compile(double left, double right)
{
	return pow(right, 1.0 / left);
}
