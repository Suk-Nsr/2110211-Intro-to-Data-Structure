#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <queue>
#include "priority_queue.h"

template <typename T, typename Comp>
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const
{
  std::vector<T> r;
  std::queue<int> indexMemory;
  indexMemory.push(0);
  int level = 0, dataCount = 0;

  while (dataCount < this->mSize)
  {
    dataCount = (dataCount * 2) + 1;
    level++;
  }

  if (k > level)
  {
    return r;
  }
  else
  {
    while (k != 0)
    {
      int memorySize = indexMemory.size();
      while (memorySize--)
      {
        if ((indexMemory.front() * 2) + 1 < this->mSize)
        {
          indexMemory.push((indexMemory.front() * 2) + 1);
        }
        if ((indexMemory.front() * 2) + 2 < this->mSize)
        {
          indexMemory.push((indexMemory.front() * 2) + 2);
        }
        indexMemory.pop();
      }
      k--;
    }
  }

  r.reserve(indexMemory.size());
  
  while (!(indexMemory.empty()))
  {
    r.push_back(this->mData[indexMemory.front()]);
    indexMemory.pop();
  }

  std::sort(r.rbegin(), r.rend(), mLess);

  return r;
}

#endif
