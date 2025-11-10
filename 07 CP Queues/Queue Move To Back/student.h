#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  T temp = mData[(mFront + pos) % mCap];
  size_t i = pos;

  for (i; i < mSize - 1; i++)
  {
    mData[(mFront + i) % mCap] = mData[(mFront + i + 1) % mCap];
  }

  mData[(mFront + i) % mCap] = temp;
}

#endif
