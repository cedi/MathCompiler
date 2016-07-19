# MathCompiler
Mathematic Compiler in C++.

# Usage
To use the compiler, include MathCompiler.h:

    #include "path/to/include/MathCompiler.h"

create an Compiler-Object and call the compile-function:
    
    MathCompiler::Compiler compiler;
    cout << compiler.compile("2*2+2^2*(2+5)+2 root 25") << endl;
  
> 37

Like you can see, the compiler could deal with a little more complex statements and the best about this compiler:
You can add your own operands verry easy.

# Add an new Operator
To add an ner operator, just create a class, which inerhits from AbstractBinaryOperator or AbstractUnaryOperator. 
You could inerhit from AbstractOperator or IOperator to provide your own Operator-Logic.

## Example: Add support for root
1. Create a new class, called OperatorRoot, which inerits from AbstractUnaryOperator, put it in the Namespace MathCompiler::Operator and implement the compile-method:
    <code>
    namespace MathCompiler
    {
    	namespace Operator
    	{
    		class OperatorRoot : public AbstractBinaryOperator
    		{
    		public:
    			OperatorRoot();
    
    		protected:
    			virtual double compile(double left, double right);
    		};
    	}
    }
    </code>
2. Implement the constructor to match your requirements:
    OperatorRoot::OperatorRoot()
    		: AbstractBinaryOperator(OperatorPriorityEnum::Function, CalculationDirectionEnum::Forward, "root")
    { }

3. Implement the compile-Function
    double OperatorRoot::compile(double left, double right)
    {
    	return pow(right, 1.0 / left);
    }
    
    
