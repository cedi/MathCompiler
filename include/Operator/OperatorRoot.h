//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractBinaryOperator.h"

#ifndef MATHCOMPILER_V2_OPERATORROOT_H
#define MATHCOMPILER_V2_OPERATORROOT_H

namespace MathCompiler
{
	namespace Operator
	{
		class OperatorRoot : public AbstractBinaryOperator
		{
		public:
			OperatorRoot();

		protected:
			virtual double compile(double left, double right);
		};
	}
}

#endif //MATHCOMPILER_V2_OPERATORROOT_H
