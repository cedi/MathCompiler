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
string& MathematicString::replaceAll(const char* oldStr, const char* newStr)
{
	size_t start_pos = 0;
	while((start_pos = this->find(oldStr, start_pos)) != std::string::npos)
	{
		this->replace(start_pos, strlen(oldStr), newStr);
		start_pos += strlen(newStr);
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
			sprintf(bufExternal, "%s-", op);

			char bufInternal[10];
			sprintf(bufInternal, "%s_", op);

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
	// Convert all other negative signs
	for(const auto& op : OperatorFactory::getInstance().getOperatorsList()) {
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
tuple<int, int> MathematicString::getOperatorIdxFromStr(const Operator::IOperator* op) const
{
	int index = -1;

	if(op->getDirectionEnum() == CalculationDirectionEnum::Forward) {
		index = static_cast<int>(find(op->getOperatorString()));
	}
	else {
		index = static_cast<int>(rfind(op->getOperatorString()));
	}

	int length = static_cast<int>(strlen(op->getOperatorString()));

	return pair<int, int>(index, length);
}

//
//
//
MathematicString MathematicString::getSubExpression(const Operator::IOperator& op, size_t index, size_t length)
{
	vector<const char*> operatorList = OperatorFactory::getInstance().getOperatorsList();
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
		if(idx != string::npos && idx > idxBeforeOp && idx < idxAfterOp)
			idxBeforeOp = idx;
	}

	if(idxAfterOp == 0 && idxBeforeOp == 0)
	{
		size_t count = 0;

		for(auto item : operatorList)
		{
			count += std::count(this->begin(), this->end(), *item);
		}

		if(count == 1)
		{
			return *this;
		}
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