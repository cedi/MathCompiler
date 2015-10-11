//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractOperator.h"

#ifndef MATHCOMPILER_V2_BINARYOPERATOR_H
#define MATHCOMPILER_V2_BINARYOPERATOR_H

namespace MathCompiler
{
	namespace Operator
	{
		class AbstractBinaryOperator : public AbstractOperator
		{
		public:
			AbstractBinaryOperator(OperatorPriorityEnum priorityEnum
								   , CalculationDirectionEnum directionEnum
								   , const char* operatorStr
								  );

		public:
			virtual const char* compile(const char* expression);

		protected:
			virtual double compile(double left, double right) = 0;
		};
	}
}

#endif //MATHCOMPILER_V2_BINARYOPERATOR_H
