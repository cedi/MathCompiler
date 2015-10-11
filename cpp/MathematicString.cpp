//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../include/MathematicString.h"
#include "../include/OperatorFactory.h"

using namespace std;
using namespace MathCompiler;

MathematicString::MathematicString(const char* str) : string(str)
{ }

MathematicString::MathematicString(std::string str)
		: string(str)
{ }

MathematicString::MathematicString(MathematicString& str) : string(str.str())
{ }

//
// Replace all occurrences
//
string& MathematicString::replaceAll(const char* oldStr, const char* newStr)
{
	size_t start_pos = 0;

	while((start_pos = find(oldStr, start_pos)) != std::string::npos)
	{
		replace(start_pos, strlen(oldStr), newStr);
		start_pos += strlen(newStr); // ...
	}

	return *this;
}

//
// Convert to an internal working string
//
bool MathematicString::normalize(bool toInternal)
{
	if(length() <= 0)
		return true;

	if(true == toInternal)
	{
		// Convert negative signs to internal negative sign

		// First char -? Convert to negative sign
		if('-' == at(0))
		{
			at(0) = '_';
		}

		// Convert all other negative signs
		for(const auto& op : OperatorFactory::getInstance().getOperatorsList())
		{
			char bufExternal[10];
			sprintf(bufExternal, "%s-", op);

			char bufInternal[10];
			sprintf(bufInternal, "%s_", op);

			replaceAll(bufExternal, bufInternal);
		}
	}
	else
	{
		// Convert all internal negative signs
		replaceAll("_", "-");
	}

	return false;
}

//
// Check if operators are available in this string
//
bool MathematicString::isContainingOperator() const
{
	// Convert all other negative signs
	for(const auto& op : OperatorFactory::getInstance().getOperatorsList())
	{
		if(0 != find(op))
			return true;
	}

	return false;
}

//
// find one of the strings in parameter
//
bool MathematicString::findOneOf(const vector<string>& toFind) const
{
	for(auto iter : toFind)
	{
		if(find(iter.c_str()) > -1)
			return true;
	}

	return false;
}

//
// Get the first sub expression from an given operator list with a given direction
//
tuple<int, int> MathematicString::getOperatorIdxFromStr(CalculationDirectionEnum direction,
		const char* op) const
{
	int index = -1;

	if(direction == CalculationDirectionEnum::Forward)
		index = static_cast<int>(find(op));
	else
		index = static_cast<int>(rfind(op));

	int length = static_cast<int>(strlen(op));

	return pair<int, int>(index, length);
}

//
//
//
MathematicString MathematicString::getSubExpression(const Operator::IOperator& op, int index, int length)
{
	return MathematicString("");
}