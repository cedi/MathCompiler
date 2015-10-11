//
// Created by Cedric Kienzler on 11.10.15.
//

#include "Operator/IOperator.h"
#include <map>

#ifndef MATHCOMPILER_OPERATORFACTORY_H
#define MATHCOMPILER_OPERATORFACTORY_H

namespace MathCompiler
{
	class OperatorFactory
	{
	private:
		OperatorFactory();
		static OperatorFactory instance;

	public:
		static OperatorFactory& getInstance();

	public:
		Operator::IOperator* getOperator(const char* op);
		void addOperator(Operator::IOperator* op);

	private:
		std::map<const char*, Operator::IOperator*> operatorMap;
	};
}
#endif //MATHCOMPILER_OPERATORFACTORY_H
