//
// Created by Cedric Kienzler on 11.10.15.
//

#include "AbstractBinaryOperator.h"

#ifndef MATHCOMPILER_V2_OPERATORDIVISION_H
#define MATHCOMPILER_V2_OPERATORDIVISION_H

namespace MathCompiler
{
	namespace Operator
	{
		class OperatorDivision : public AbstractBinaryOperator
		{
		public:
			OperatorDivision();

		protected:
			virtual double compile(double left, double right);
		};
	}
}


#endif //MATHCOMPILER_V2_OPERATORDIVISION_H
