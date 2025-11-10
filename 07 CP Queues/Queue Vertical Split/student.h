#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  output.clear();
  std::vector<int> times(k, this->mSize / k);
  CP::queue<T> copied(*this);

  for (int i = 0; i < (this->mSize % k); i++)
  {
    times[i]++;
  }

  for (int time : times)
  {
    std::queue<T> temp;
    for (int i = 0; i < time; i++)
    {
      temp.push(copied.front());
      copied.pop();
    }
    output.push_back(temp);
  }
}

#endif
