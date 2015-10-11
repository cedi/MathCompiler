//
// Created by Cedric Kienzler on 11.10.15.
//

#include "../include/OperatorFactory.h"
#include "../include/Operator/OperatorDivision.h"
#include "../include/Operator/OperatorExponent.h"
#include "../include/Operator/OperatorMinus.h"
#include "../include/Operator/OperatorMultiplication.h"
#include "../include/Operator/OperatorPlus.h"

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