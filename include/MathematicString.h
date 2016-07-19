//
// Created by Cedric Kienzler on 11.10.15.
//

#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "OperatorEnum.h"
#include "Operator/IOperator.h"

#ifndef MATHCOMPILER_MATHEMATICSTRING_H
#define MATHCOMPILER_MATHEMATICSTRING_H

namespace MathCompiler
{
	class MathematicString : public std::string
	{
	public:
		MathematicString(const char* str);
		MathematicString(std::string str);
		MathematicString(MathematicString& str);

	public:
		bool normalize(bool toInternal = true);
		bool isContainingOperator() const;
		bool findOneOf(const std::vector<std::string>& toFind) const;

	public:
		size_t count(const std::string& substr);

	public:
		std::string str() const { return static_cast<std::string>(*this); }
		std::string& replaceAll(const char* oldStr, const char* newStr);
		std::pair<int, int> getOperatorIdxFromStr(const Operator::IOperator* op) const;
		MathematicString getSubExpression(const Operator::IOperator& op, size_t index, size_t length);
	};
}

#endif //MATHCOMPILER_MATHEMATICSTRING_H
