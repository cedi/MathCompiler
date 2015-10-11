//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractBinaryOperator.h"

#ifndef MATHCOMPILER_V2_OPERATORMULTIPLICATION_H
#define MATHCOMPILER_V2_OPERATORMULTIPLICATION_H

namespace MathCompiler
{
	namespace Operator
	{
		class OperatorMultiplication : public AbstractBinaryOperator
		{
		public:
			OperatorMultiplication();

		protected:
			virtual double compile(double left, double right);
		};
	}
}

#endif //MATHCOMPILER_V2_OPERATORMULTIPLICATION_H
