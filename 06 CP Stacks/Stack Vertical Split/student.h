#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  std::vector<size_t> times(k, static_cast<int>(this->mSize / k));

  for (int i = 0; i < this->mSize % k; i++)
  {
    times[i]++;
  }

  // Make a copy of the stack to avoid modifying the original (const) stack
  CP::stack<T> tempStack = *this;

  for (int i = 0; i < k; i++)
  {
    output.push_back(std::stack<T>());
    std::vector<T> temp;

    while (times[i] > 0 && !tempStack.empty())
    {
      temp.push_back(tempStack.top());
      tempStack.pop();
      times[i]--;
    }

    for (int j = temp.size(); j > 0; j--)
    {
      output[i].push(temp[j - 1]);
    }
  }
}

#endif
