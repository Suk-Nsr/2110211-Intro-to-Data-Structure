#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls)
{
  for (auto &list : ls)
  {
    if (list.mSize == 0)
    {
      continue;
    }

    this->mHeader->prev->next = list.mHeader->next;
    list.mHeader->prev->next = this->mHeader;
    list.mHeader->next->prev = this->mHeader->prev;
    this->mHeader->prev = list.mHeader->prev;

    list.mHeader->next = list.mHeader;
    list.mHeader->prev = list.mHeader;

    this->mSize = this->mSize + list.mSize;
    list.mSize = 0;
  }
}

#endif
