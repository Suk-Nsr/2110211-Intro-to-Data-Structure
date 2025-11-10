#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  std::sort(pos.begin(), pos.end());
  CP::queue<T> temp;
  int posIndex = 0;
  int size = this->size();

  for (int i = 0; i < size; i++)
  {
    if (i == pos[posIndex])
    {
      this->pop();
      posIndex++;
    }
    else
    {
      temp.push(this->front());
      this->pop();
    }
  }

  std::swap(*this,temp);
}

#endif
