#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T &CP::vector_no_move<T>::operator[](int idx)
{
  // your code here
  auto it = std::upper_bound(aux.begin(), aux.end(), idx);
  size_t block = it - aux.begin();
  int offset;

  if (block == 0)
  {
    offset = idx;
  }
  else
  {
    offset = idx - (aux[block - 1]);
  }

  return mData[block][offset];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook()
{
  // your code here
  // you MAY need this function
  this->aux.push_back(mCap);
}

#endif
