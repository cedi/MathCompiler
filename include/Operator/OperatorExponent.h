//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractBinaryOperator.h"

#ifndef MATHCOMPILER_V2_OPERATOREXPONENT_H
#define MATHCOMPILER_V2_OPERATOREXPONENT_H

namespace MathCompiler
{
	namespace Operator
	{
		class OperatorExponent : public AbstractBinaryOperator
		{
		public:
			OperatorExponent();

		protected:
			virtual double compile(double left, double right);
		};
	}
}

#endif //MATHCOMPILER_V2_OPERATOREXPONENT_H
