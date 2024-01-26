#include <iostream>
#include <stack>

#include "Stack/stack.h"

void test_cp_stack()
{
		// Testing std::stack
		std::stack<int> stdStack;
		stdStack.push(1);
		stdStack.push(2);
		stdStack.push(3);

		std::cout << "Testing std::stack:" << std::endl;
		while (!stdStack.empty()) {
				std::cout << stdStack.top() << " ";
				stdStack.pop();
		}
		std::cout << std::endl;

		// Testing cp::stack
		cp::stack<int> cpStack;
		cpStack.push(1);
		cpStack.push(2);
		cpStack.push(3);

		std::cout << "Testing cp::stack:" << std::endl;
		while (!cpStack.empty()) {
				std::cout << cpStack.top() << " ";
				cpStack.pop();
		}
		std::cout << std::endl;

		// Testing empty stack
		std::cout << "Testing empty stack:" << std::endl;
		std::stack<int> emptyStdStack;
		cp::stack<int> emptyCpStack;

		std::cout << "std::stack is empty: " << emptyStdStack.empty() << std::endl;
		std::cout << "cp::stack is empty: " << emptyCpStack.empty() << std::endl;

		// Testing stack size
		std::cout << "Testing stack size:" << std::endl;
		stdStack.push(4);
		stdStack.push(5);
		cpStack.push(4);
		cpStack.push(5);

		std::cout << "std::stack size: " << stdStack.size() << std::endl;
		std::cout << "cp::stack size: " << cpStack.size() << std::endl;

		// Testing top element
		std::cout << "Testing top element:" << std::endl;
		std::cout << "std::stack top element: " << stdStack.top() << std::endl;
		std::cout << "cp::stack top element: " << cpStack.top() << std::endl;

		// Testing copy constructor
		std::cout << "Testing copy constructor:" << std::endl;
		cp::stack<int> copiedCpStack(cpStack);
		while (!copiedCpStack.empty()) {
				std::cout << copiedCpStack.top() << " ";
				copiedCpStack.pop();
		}
		std::cout << std::endl;

		// Testing move constructor
		std::cout << "Testing move constructor:" << std::endl;
		cp::stack<int> movedCpStack(std::move(cpStack));
		while (!movedCpStack.empty()) {
				std::cout << movedCpStack.top() << " ";
				movedCpStack.pop();
		}
		std::cout << std::endl;

		copiedCpStack.push(4);
		copiedCpStack.push(5);
		copiedCpStack.push(42);
		copiedCpStack.push(54);
		copiedCpStack.push(6);
		copiedCpStack.push(7);
		copiedCpStack.push(88);
		copiedCpStack.push(8);

	// Testing copy assignment operator
		std::cout << "Testing copy assignment operator:" << std::endl;
		cpStack = copiedCpStack;
		while (!cpStack.empty()) {
				std::cout << cpStack.top() << " ";
				cpStack.pop();
		}
		std::cout << std::endl;


		movedCpStack.push(4);
		movedCpStack.push(5);
		movedCpStack.push(42);
		movedCpStack.push(54);
		movedCpStack.push(6);
		movedCpStack.push(7);
		movedCpStack.push(88);
		movedCpStack.push(8);


		// Testing move assignment operator
		std::cout << "Testing move assignment operator:" << std::endl;
		cpStack = std::move(movedCpStack);
		while (!cpStack.empty()) {
				std::cout << cpStack.top() << " ";
				cpStack.pop();
		}
		std::cout << std::endl;
}

