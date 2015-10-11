//
// Created by Cedric Kienzler on 11.10.15.
//

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
								   , const char* operatorStr
								   , bool operatorRightOfNumber = true
								  );

		public:
			virtual const char* compile(const char* expression);

		protected:
			virtual double compile(double number) = 0;

		private:
			bool operatorRightOfNumber;
		};
	}
}

#endif //MATHCOMPILER_ABSTRACTUNARYOPERATOR_H
