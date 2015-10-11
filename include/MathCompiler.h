//
// Created by Cedric Kienzler on 11.10.15.
//

#include <string>

#ifndef MATHCOMPILER_MATHCOMPILER_H
#define MATHCOMPILER_MATHCOMPILER_H

class MathCompiler
{
public:
	const char* compile(const char* expression);

private:
	void compileBrackets(std::string* expression);
};


#endif //MATHCOMPILER_MATHCOMPILER_H
