#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <cmath>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  std::vector<T> temp;
  for (size_t i = 0; i < std::min(static_cast<int>(mSize), static_cast<int>(pow(2,static_cast<int>(k)) - 1)); i++)
  {
    temp.push_back(mData[i]);
  }
  std::sort(temp.begin(), temp.end(), mLess);
  return temp[temp.size() - k];
}

#endif
