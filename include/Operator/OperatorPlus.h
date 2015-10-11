//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractBinaryOperator.h"

#ifndef MATHCOMPILER_V2_OPERATORPLUS_H
#define MATHCOMPILER_V2_OPERATORPLUS_H

namespace MathCompiler
{
	namespace Operator
	{
		class OperatorPlus : public AbstractBinaryOperator
		{
		public:
			OperatorPlus();

		protected:
			virtual double compile(double left, double right);
		};
	}
}

#endif //MATHCOMPILER_V2_OPERATORPLUS_H
