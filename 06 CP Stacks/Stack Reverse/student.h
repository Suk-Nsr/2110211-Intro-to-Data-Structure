#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	if (first < last)
	{	
		first = std::min(this->size() - 1, first);
		last = std::min(this->size() - 1, last);
		std::vector<T> nonReversed;
		std::vector<T> reversed;

		for (size_t i = 0; i < first; i++)
		{
			nonReversed.push_back(this->top());
			this->pop();
		}

		for (size_t i = 0; i <= last - first; i++)
		{
			reversed.push_back(this->top());
			this->pop();
		}

		for (int i = 0; i < reversed.size(); i++)
		{
			this->push(reversed[i]);
		}

		for (int i = static_cast<int>(nonReversed.size()) - 1; i >= 0; i--)
		{
			this->push(nonReversed[i]);
		}
	}
}

#endif
