//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../include/MathCompiler.h"

using namespace std;

const char* MathCompiler::compile(const char* expression)
{
	return 0;
}

void MathCompiler::compileBrackets(string* expression)
{
	MathCompiler compiler(*this);

	unsigned long idxClosingBracket;
	unsigned long idxOpeningBracket;
	do
	{
		idxClosingBracket = expression->rfind(")");
		idxOpeningBracket = expression->rfind("(", idxClosingBracket);

		if(idxOpeningBracket <= -1 || idxClosingBracket <= -1)
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
	while(idxOpeningBracket > -1 && idxClosingBracket > -1);
}