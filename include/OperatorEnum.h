//
// Created by Cedric Kienzler on 11.10.15.
//

#ifndef MATHCOMPILER_V2_OPERATORENUM_H
#define MATHCOMPILER_V2_OPERATORENUM_H

enum class OperatorPriorityEnum
{
	Function,           // root
	Exponent,           // ^
	DotOperator,        // * and /
	LineOperator,       // + and -
};

enum class CalculationDirectionEnum
{
	Forward, Backward
};

#endif //MATHCOMPILER_V2_OPERATORENUM_H
