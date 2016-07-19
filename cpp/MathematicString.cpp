//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../include/MathematicString.h"
#include "../include/OperatorFactory.h"

using namespace std;
using namespace MathCompiler;

MathematicString::MathematicString(const char* str)
		: string(str)
{ }

MathematicString::MathematicString(std::string str)
		: string(str)
{ }

MathematicString::MathematicString(MathematicString& str)
		: string(str.str())
{ }

//
// Replace all occurrences
//
string& MathematicString::replaceAll(const string& oldStr, const string& newStr)
{
	size_t start_pos = 0;
	while((start_pos = this->find(oldStr, start_pos)) != std::string::npos)
	{
		this->replace(start_pos, oldStr.length(), newStr);
		start_pos += newStr.length();
	}

	return *this;
}

//
// Convert to an internal working string
//
bool MathematicString::normalize(bool toInternal)
{
	if(length() <= 0) {
		return true;
	}

	if(true == toInternal) {
		// Convert negative signs to internal negative sign

		// First char -? Convert to negative sign
		if('-' == at(0)) {
			at(0) = '_';
		}

		// Convert all other negative signs
		for(const auto& op : OperatorFactory::getInstance().getOperatorsList()) {
			char bufExternal[10];
			sprintf_s(bufExternal, "%s-", op.c_str());

			char bufInternal[10];
			sprintf_s(bufInternal, "%s_", op.c_str());

			replaceAll(bufExternal, bufInternal);
		}
	}
	else {
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
	for(auto op : OperatorFactory::getInstance().getOperatorsList()) {
		if(string::npos != find(op)) {
			return true;
		}
	}

	return false;
}

//
// find one of the strings in parameter
//
bool MathematicString::findOneOf(const vector<string>& toFind) const
{
	for(auto iter : toFind) {
		if(find(iter.c_str()) != string::npos) {
			return true;
		}
	}

	return false;
}

//
// Get the first sub expression from an given operator list with a given direction
//
pair<int, int> MathematicString::getOperatorIdxFromStr(const Operator::IOperator* op) const
{
	int index = -1;

	if(op->getDirectionEnum() == CalculationDirectionEnum::Forward) {
		index = static_cast<int>(find(op->getOperatorString()));
	}
	else {
		index = static_cast<int>(rfind(op->getOperatorString()));
	}

	int length = static_cast<int>(strlen(op->getOperatorString().c_str()));

	return pair<int, int>(index, length);
}

// 
// Count the occurrences of a a substring
// 
size_t MathematicString::count(const std::string& substr)
{
	if(substr.length() == 0)
	{
		return 0;
	}

	int count = 0;
	for(size_t offset = this->find(substr)
		; offset != std::string::npos
		; offset = this->find(substr, offset + substr.length())
		)
	{
		count++;
	}

	return count;
}

//
//
//
MathematicString MathematicString::getSubExpression(const Operator::IOperator& op, size_t index, size_t length)
{
	auto operatorList = OperatorFactory::getInstance().getOperatorsList();
	size_t idxAfterOp = 0;
	size_t idxBeforeOp = 0;

	for(auto item : operatorList)
	{
		size_t idx = find(item, (index + length));
		if(idx != string::npos && (idxAfterOp == 0 || idx < idxAfterOp))
			idxAfterOp = idx;
	}

	for(auto item : operatorList)
	{
		size_t idx = rfind(item, index -1);
		if(idxAfterOp != 0)
		{
			if(idx != string::npos && idx > idxBeforeOp && idx < idxAfterOp)
			{
				idxBeforeOp = idx;
			}
		}
		else
		{
			if(idx != string::npos && idx > idxBeforeOp)
			{
				idxBeforeOp = idx;
			}
		}

	}

	if(idxAfterOp == 0 && idxBeforeOp == 0)
	{
		size_t cntr = 0;

		for(auto item : operatorList)
		{
			cntr += count(item);
		}

		if(cntr == 1)
		{
			return *this;
		}
	}

	// Idx after op not found - so it is the last operator
	if(idxAfterOp == 0 &&  idxAfterOp < idxBeforeOp)
	{
		idxAfterOp = this->length();
	}

	size_t len = idxAfterOp - idxBeforeOp;
	if(idxBeforeOp > 0)
	{
		idxBeforeOp++;
		len--;
	}

	MathematicString tmp(this->substr(idxBeforeOp, len));
	return tmp;
}