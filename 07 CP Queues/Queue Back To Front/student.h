#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  if (this->mSize > 0)
  {
    this->mData[(this->mFront + this->mCap - 1) % this->mCap] = this-> mData[(this->mFront + this->mSize - 1) % this->mCap];
    this->mFront = (this->mFront + this->mCap - 1) % this->mCap;
  }
}

#endif
