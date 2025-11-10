#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  int count = 0;

  for (auto i = last; i != first; i--)
  {
    count++;
  }
  
  mData = new T[count]();
  mCap = count;
  mSize = count;
  auto it = last;
  it--;

  for (int i = 0; i < mSize; i++)
  {
    mData[i] = *it;
    it--;
  }
}

#endif
