//
// Created by Cedric Kienzler on 11.10.15.
//

#include <string>
#include "../include/OperatorEnum.h"

#ifndef MATHCOMPILER_MATHCOMPILER_H
#define MATHCOMPILER_MATHCOMPILER_H

namespace MathCompiler
{
	class MathematicString;

	class Compiler
	{
	public:
		const char* compile(const char* expression);

	private:
		void compileBrackets(std::string* expression);

		void compileSingleOperation(CalculationDirectionEnum direction, MathematicString* expression);
	};
}

#endif //MATHCOMPILER_MATHCOMPILER_H
