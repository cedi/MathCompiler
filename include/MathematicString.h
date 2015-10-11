//
// Created by Cedric Kienzler on 11.10.15.
//

#include <string>
#include <vector>
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
		bool       normalize(bool toInternal = true);
		bool       isContainingOperator() const;
		bool       findOneOf(const std::vector<std::string>& toFind) const;

	public:
		std::string str() const { return static_cast<std::string>(*this); }
		const char* c_str()	const { return static_cast<std::string>(*this).c_str(); }
		std::string& replaceAll(const char* oldStr, const char* newStr);
		std::tuple<int, int> getOperatorIdxFromStr(CalculationDirectionEnum direction, const char* op) const;
		MathematicString getSubExpression(const Operator::IOperator& op, int index, int length);
	};
}

#endif //MATHCOMPILER_MATHEMATICSTRING_H
