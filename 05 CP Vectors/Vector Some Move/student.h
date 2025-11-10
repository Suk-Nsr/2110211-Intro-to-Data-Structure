#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value)
{

  auto it = std::upper_bound(aux.begin(), aux.end(), index);
  size_t block = it - aux.begin();
  int vSize = value.size();
  int offset;

  if (block == 0)
  {
    offset = index;
  }
  else
  {
    offset = index - aux[block - 1];
  }

  if (block == mData.size())
  {
    mData.push_back(value);
    aux.push_back(aux.back() + value.size());
  }
  else if (offset == 0)
  {
    mData.insert(mData.begin() + block, value);
    int s;

    if (block == 0)
    {
      s = vSize;
    }
    else
    {
      s = aux[block - 1] + vSize;
    }

    aux.insert(aux.begin() + block, s);

    for (size_t i = block + 1; i < aux.size(); ++i)
    {
      aux[i] += vSize;
    }
  }
  else if (mData[block].size() + vSize > 1000)
  {
    int tailSize = mData[block].size() - offset;
    std::vector<T> tail(mData[block].begin() + offset, mData[block].end());
    mData[block].erase(mData[block].begin() + offset, mData[block].end());
    mData[block].insert(mData[block].end(), value.begin(), value.end());
    mData.insert(mData.begin() + block + 1, tail);

    aux[block] += vSize - tailSize;
    int newAux = aux[block] + tail.size();
    aux.insert(aux.begin() + block + 1, newAux);
    for (size_t i = block + 2; i < aux.size(); ++i)
    {
      aux[i] += vSize;
    }
  }
  else
  {
    mData[block].insert(mData[block].begin() + offset, value.begin(), value.end());
    for (size_t i = block; i < aux.size(); ++i)
    {
      aux[i] += vSize;
    }
  }

  mSize += vSize;
  mCap += vSize;
}

#endif