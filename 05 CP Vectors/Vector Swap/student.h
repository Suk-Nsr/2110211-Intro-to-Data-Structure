#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
  // your code here
  T *mData = other.mData;
  size_t mCap = other.mCap;
  size_t mSize = other.mSize;

  other.mData = this->mData;
  other.mCap = this->mCap;
  other.mSize = this->mSize;

  this->mData = mData;
  this->mCap = mCap;
  this->mSize = mSize;
}

#endif
