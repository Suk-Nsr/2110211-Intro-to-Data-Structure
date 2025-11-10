#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  if (this->mSize == 0)
  {
    return -1;
  }
  else
  {
    int height = -1, nodeCount = 0; 
    
    while (nodeCount < this->mSize)
    {
      nodeCount = (nodeCount * 2) + 1;
      height++;
    }

    return height;
  }
}

#endif

