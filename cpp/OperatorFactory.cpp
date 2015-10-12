//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../include/OperatorFactory.h"
#include "../include/Operator/OperatorDivision.h"
#include "../include/Operator/OperatorExponent.h"
#include "../include/Operator/OperatorMinus.h"
#include "../include/Operator/OperatorMultiplication.h"
#include "../include/Operator/OperatorPlus.h"
#include "../include/Operator/OperatorRoot.h"

using namespace std;
using namespace MathCompiler;

OperatorFactory OperatorFactory::instance;

//
// Constructor
//
OperatorFactory::OperatorFactory()
{
	addOperator(static_cast<Operator::IOperator*>(new Operator::OperatorDivision()));
	addOperator(static_cast<Operator::IOperator*>(new Operator::OperatorMultiplication()));
	addOperator(static_cast<Operator::IOperator*>(new Operator::OperatorPlus()));
	addOperator(static_cast<Operator::IOperator*>(new Operator::OperatorMinus()));
	addOperator(static_cast<Operator::IOperator*>(new Operator::OperatorExponent()));
	addOperator(static_cast<Operator::IOperator*>(new Operator::OperatorRoot()));
}

//
// get the Singleton
//
OperatorFactory& OperatorFactory::getInstance()
{
	return instance;
}

//
// get the Operator
//
Operator::IOperator* OperatorFactory::getOperator(const char* op)
{
	return operatorMap[op];
}

//
// Insert an operator
//
void OperatorFactory::addOperator(Operator::IOperator* op)
{
	operatorMap[op->getOperatorString()] = op;
}

//
// Get all registred Operators
//
vector<const char*> OperatorFactory::getOperatorsList() const
{
	vector<const char*> vec;

	for(map<const char*, MathCompiler::Operator::IOperator*>::const_iterator it = operatorMap.begin(); it != operatorMap.end(); it++)
	{
		vec.push_back(it->first);
	}

	return vec;
}

vector<const char*> OperatorFactory::getOperatorsList(OperatorPriorityEnum priority) const
{
	vector<const char*> vec;

	for(map<const char*, MathCompiler::Operator::IOperator*>::const_iterator it = operatorMap.begin(); it != operatorMap.end(); it++)
	{
		if(it->second->getPriority() == priority) {
			vec.push_back(it->first);
		}
	}

	return vec;
}

vector<const char*> OperatorFactory::getOperatorsList(CalculationDirectionEnum direction) const
{
	vector<const char*> vec;

	for(map<const char*, MathCompiler::Operator::IOperator*>::const_iterator it = operatorMap.begin(); it != operatorMap.end(); it++)
	{
		if(it->second->getDirectionEnum() == direction) {
			vec.push_back(it->first);
		}
	}

	return vec;
}

vector<const char*> OperatorFactory::getOperatorsList(OperatorPriorityEnum priority, CalculationDirectionEnum direction) const
{
	vector<const char*> vec;

	for(map<const char*, MathCompiler::Operator::IOperator*>::const_iterator it = operatorMap.begin(); it != operatorMap.end(); it++)
	{
		if(it->second->getPriority() == priority && it->second->getDirectionEnum() == direction) {
			vec.push_back(it->first);
		}
	}

	return vec;
}

set<OperatorPriorityEnum> OperatorFactory::getPriorityList() const
{
	set<OperatorPriorityEnum> set1;
	vector<OperatorPriorityEnum> vec;

	for(map<const char*, MathCompiler::Operator::IOperator*>::const_iterator it = operatorMap.begin(); it != operatorMap.end(); it++)
	{
		set1.insert(it->second->getPriority());
	}

	return set1;
}