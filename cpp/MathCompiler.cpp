//
// Created by Cedric Kienzler on 11.10.15.
//

#include <algorithm>
#include "../include/MathCompiler.h"
#include "../include/MathematicString.h"
#include "../include/OperatorFactory.h"

using namespace std;
using namespace MathCompiler;

//
// Compile the string
//
string Compiler::compile(const string& expression)
{
	try
	{
		MathematicString mathExpression(expression);

		// Only compile if there are operators inside the string
		if(false == mathExpression.isContainingOperator())
			return expression;

		// First of all, compile the brackets
		compileBrackets(&mathExpression);

		mathExpression.normalize(true);

		compileSingleOperation(CalculationDirectionEnum::Backward, &mathExpression);
		compileSingleOperation(CalculationDirectionEnum::Forward, &mathExpression);

		mathExpression.normalize(false);

		return mathExpression.c_str();
	}
	catch(exception* pE)
	{
//		if(true == returnErrorAsResult)
//		{
//			return pE->getErrMsg();
//		}
//		else
		{
			throw pE;
		}
	}
}

//
// first compile inside the brackets
//
void Compiler::compileBrackets(string* expression)
{
	Compiler compiler(*this);

	unsigned long idxClosingBracket;
	unsigned long idxOpeningBracket;
	do
	{
		idxClosingBracket = expression->rfind(")");
		idxOpeningBracket = expression->rfind("(", idxClosingBracket);

		if(idxOpeningBracket == string::npos || idxClosingBracket == string::npos)
			break;

		// calculate the length between
		unsigned long lenBrackets = idxClosingBracket - idxOpeningBracket +1;

		// extract string inside brackets
		string extractedString = expression->substr(idxOpeningBracket, lenBrackets);

		// trim brackets
		extractedString = extractedString.substr(1, extractedString.length() -2);

		// compile the string
		string compiled = compiler.compile(extractedString.c_str());

		// Replace it in the string
		*expression = expression->replace(idxOpeningBracket, lenBrackets, compiled.c_str());
	}
	while(idxOpeningBracket != string::npos && idxClosingBracket != string::npos);
}

//
// first compile inside the brackets
//
void Compiler::compileSingleOperation(CalculationDirectionEnum direction, MathematicString* expression)
{
	for(auto priority : OperatorFactory::getInstance().getPriorityList())
	{
		for(auto op : OperatorFactory::getInstance().getOperatorsList(priority, direction))
		{
			Operator::IOperator* anOperator = OperatorFactory::getInstance().getOperator(op);

			while(anOperator && expression->find(anOperator->getOperatorString()) != string::npos)
			{
				pair<int, int> ret = expression->getOperatorIdxFromStr(anOperator);
				int index = ret.first;
				int length = ret.second;

				MathematicString subExpr = expression->getSubExpression(*anOperator, index, length);

				string result = anOperator->compile(subExpr);

				expression->replaceAll(subExpr, result);
			}
		}
	}
}