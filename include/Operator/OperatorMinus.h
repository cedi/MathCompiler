//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractBinaryOperator.h"

#ifndef MATHCOMPILER_V2_OPERATORMINUS_H
#define MATHCOMPILER_V2_OPERATORMINUS_H

namespace MathCompiler
{
	namespace Operator
	{
		class OperatorMinus : public AbstractBinaryOperator
		{
		public:
			OperatorMinus();

		protected:
			virtual double compile(double left, double right);
		};
	}
}

#endif //MATHCOMPILER_V2_OPERATORMINUS_H
