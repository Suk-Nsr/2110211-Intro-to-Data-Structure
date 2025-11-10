#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  std::vector<std::vector<T>> tempVector(k);
  CP::stack<T> tempStack;
  tempStack = *this;
  int i = 0;

  while (!tempStack.empty())
  {
    tempVector[i].push_back(tempStack.top());
    tempStack.pop();
    i++;
    i %= k;
  }

  for (int j = 0; j < tempVector.size(); j++)
  {
    std::reverse(tempVector[j].begin(),tempVector[j].end());
  }

  return tempVector;
}

#endif

