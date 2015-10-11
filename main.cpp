#include <iostream>
#include "include/MathCompiler.h"

using namespace std;

int main()
{
	MathCompiler::Compiler compiler;

	cout << compiler.compile("1+1") << endl;
	cout << compiler.compile("2-2") << endl;
	cout << compiler.compile("3*3") << endl;
	cout << compiler.compile("3/4") << endl;
	cout << compiler.compile("2*2+2^2*(2+5)+2 root 25") << endl;

	return 0;
}