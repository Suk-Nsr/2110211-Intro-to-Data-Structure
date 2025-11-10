#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  //write your code here
  this->mData[pos] = value;
  this->fixUp(pos);
  this->fixDown(pos);
}

#endif
