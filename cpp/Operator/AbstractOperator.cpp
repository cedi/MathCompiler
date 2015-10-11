//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../../include/OperatorEnum.h"
#include "../../include/Operator/AbstractOperator.h"
#include <string>

using namespace MathCompiler::Operator;

AbstractOperator::AbstractOperator(OperatorPriorityEnum priorityEnum
								   , CalculationDirectionEnum directionEnum
								   , const char* operatorStr
								  )
		: priorityEnum(priorityEnum)
		  , directionEnum(directionEnum)
		  , operatorString(operatorStr)
{ }

