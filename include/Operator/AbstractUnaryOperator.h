//
// Created by Cedric Kienzler on 11.10.15.
//

#include <string>

#ifndef MATHCOMPILER_ABSTRACTUNARYOPERATOR_H
#define MATHCOMPILER_ABSTRACTUNARYOPERATOR_H

namespace MathCompiler
{
	namespace Operator
	{
		class AbstractUnaryOperator : AbstractOperator
		{
		public:
			AbstractUnaryOperator(OperatorPriorityEnum priorityEnum
								   , CalculationDirectionEnum directionEnum
								   , const std::string& operatorStr
								   , bool operatorRightOfNumber = true
								  );

		public:
			virtual std::string compile(const std::string& expression);

		protected:
			virtual double compile(double number) = 0;

		private:
			bool operatorRightOfNumber;
		};
	}
}

#endif //MATHCOMPILER_ABSTRACTUNARYOPERATOR_H
