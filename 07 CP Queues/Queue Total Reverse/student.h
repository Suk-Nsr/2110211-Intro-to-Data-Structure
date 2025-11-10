#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  if (this->aux == 0)
  {
    this->aux = 1;
  }
  else
  {
    this->aux = 0;
  }
}

template <typename T>
const T& CP::queue<T>::front() const {
  if (this->aux == 0)
  {
    return mData[mFront];
  }
  else
  {
    return mData[(mFront + mSize - 1) % mCap];
  }
}

template <typename T>
const T& CP::queue<T>::back() const {
  if (this->aux == 0)
  {
    return mData[(mFront + mSize - 1) % mCap];
  }
  else
  {
    return mData[mFront];
  }
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  if (this->aux == 0)
  {
    ensureCapacity(mSize + 1);
    mData[(mFront + mSize) % mCap] = element;
    mSize++;
  }
  else
  {
    ensureCapacity(mSize + 1);
    mData[(mFront + mCap - 1) % mCap] = element;
    mFront = (mFront + mCap - 1) % mCap;
    mSize++;
  }
}

template <typename T>
void CP::queue<T>::pop() {
  if (this->aux == 0)
  {
    mFront = (mFront + 1) % mCap;
    mSize--;
  }
  else
  {
    mSize--;
  }
}

#endif