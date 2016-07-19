//
// Created by Cedric Kienzler on 11.10.15.
//

#include "Operator/IOperator.h"
#include <map>
#include <set>
#include <vector>

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
		Operator::IOperator* getOperator(const std::string& op);
		void addOperator(Operator::IOperator* op);

		std::vector<std::string> getOperatorsList() const;
		std::vector<std::string> getOperatorsList(OperatorPriorityEnum priority) const;
		std::vector<std::string> getOperatorsList(CalculationDirectionEnum direction) const;
		std::vector<std::string> getOperatorsList(OperatorPriorityEnum priority, CalculationDirectionEnum direction) const;
		std::set<OperatorPriorityEnum> getPriorityList() const;

	private:
		std::map<std::string, Operator::IOperator*> operatorMap;
	};
}
#endif //MATHCOMPILER_OPERATORFACTORY_H
