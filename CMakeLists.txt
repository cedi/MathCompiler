cmake_minimum_required(VERSION 3.3)
project(MathCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        cpp/Operator/AbstractBinaryOperator.cpp
        cpp/Operator/OperatorPlus.cpp
        cpp/Operator/OperatorMinus.cpp
        cpp/Operator/OperatorDivision.cpp
        cpp/Operator/OperatorMultiplication.cpp
        cpp/Operator/OperatorExponent.cpp
        cpp/Operator/OperatorRoot.cpp
        cpp/Operator/AbstractOperator.cpp
        cpp/Operator/AbstractUnaryOperator.cpp
        cpp/OperatorFactory.cpp
        cpp/MathCompiler.cpp
        cpp/MathematicString.cpp)

add_executable(MathCompiler ${SOURCE_FILES})