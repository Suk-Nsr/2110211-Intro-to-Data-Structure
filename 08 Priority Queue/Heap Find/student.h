#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
  //your code here
  for (int i = 0; i < this->mSize; i++)
  {
    if (this->mData[i] == k)
    {
      return true;
    }
  }
  return false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
  //your code here
  for (int i = (mSize - 1); i >= 0; i--)
  {
    if (this->mData[i] == k)
    {
      int temp = i, height = 0;
      while (temp != 0)
      {
        temp = (temp - 1) / 2;
        height++;
      }
      return height;
    }
  }
  return -1;
}

#endif

