#ifndef __STUDENT_H_
#define __STUDENT_H_

// can include anything
#include <vector>
#include <algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos, CompareT comp)
{
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B

  std::vector<T> values;
  std::vector<size_t> index;

  for (auto it : pos)
  {
    values.push_back(*it);
    index.push_back(it - this->begin());
  }

  std::sort(values.begin(), values.end(), comp);
  std::sort(index.begin(), index.end());

  for (size_t i = 0; i < values.size(); i++)
  {
    this->mData[index[i]] = values[i];
  }
}

#endif