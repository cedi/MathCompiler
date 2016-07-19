//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../OperatorEnum.h"
#include <string>

#ifndef MATHCOMPILER_V2_IOPERATOR_H
#define MATHCOMPILER_V2_IOPERATOR_H

namespace MathCompiler
{
	namespace Operator
	{
		struct IOperator
		{
			virtual std::string compile(const std::string& expression) = 0;
			virtual OperatorPriorityEnum getPriority() const = 0;
			virtual CalculationDirectionEnum getDirectionEnum() const = 0;
			virtual std::string getOperatorString() const = 0;
		};
	}
}

#endif //MATHCOMPILER_V2_IOPERATOR_H
