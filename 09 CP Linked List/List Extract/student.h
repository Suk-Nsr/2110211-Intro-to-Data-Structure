#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T &value, iterator a, iterator b, CP::list<T> &output)
{
  auto it = a;
  while (it != b)
  {
    auto nextNode = it.ptr->next;
    if (it.ptr->data == value)
    {
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      it.ptr->next = output.mHeader->next;
      output.mHeader->next->prev = it.ptr;
      output.mHeader->next = it.ptr;
      it.ptr->prev = output.mHeader;
      ++output.mSize;
      --this->mSize;
    }
    it = nextNode;
  }
}

#endif
