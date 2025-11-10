#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <stack>

template <typename T>
void noOneEmpty(std::stack<T> &stack_a, std::stack<T> &stack_b)
{
	std::stack<T> temp;
	if (stack_b.empty())
	{
		for (int i = 0; i < stack_a.size() / 2; i++)
		{
			temp.push(stack_a.top());
			stack_a.pop();
		}
		while (!stack_a.empty())
		{
			stack_b.push(stack_a.top());
			stack_a.pop();
		}
		while (!temp.empty())
		{
			stack_a.push(temp.top());
			temp.pop();
		}
	}
}

template <typename T>
void CP::stack<T>::pop()
{
	noOneEmpty(stack_b, stack_a);
	stack_a.pop();
}

template <typename T>
const T &CP::stack<T>::top()
{
	noOneEmpty(stack_b, stack_a);
	return stack_a.top();
}

template <typename T>
const T &CP::stack<T>::bottom()
{
	noOneEmpty(stack_a, stack_b);
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T &element)
{
	noOneEmpty(stack_a, stack_b);
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom()
{
	noOneEmpty(stack_a, stack_b);
	stack_b.pop();
}
#endif