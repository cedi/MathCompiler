//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../OperatorEnum.h"
#include "IOperator.h"

#ifndef MATHCOMPILER_V2_ABSTRACTOPERATOR_H
#define MATHCOMPILER_V2_ABSTRACTOPERATOR_H

namespace MathCompiler
{
	namespace Operator
	{
		class AbstractOperator : public IOperator
		{
		public:
			AbstractOperator(OperatorPriorityEnum priorityEnum
							 , CalculationDirectionEnum directionEnum
							 , const char* operatorStr
							);

		public:
			OperatorPriorityEnum     getPriority() const { return priorityEnum; }
			CalculationDirectionEnum getDirectionEnum() const { return directionEnum; }
			const char*              getOperatorString() const { return operatorString; }

		private:
			OperatorPriorityEnum     priorityEnum;
			CalculationDirectionEnum directionEnum;
			const char*              operatorString;
		};
	}
}

#endif //MATHCOMPILER_V2_ABSTRACTOPERATOR_H
