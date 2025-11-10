#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls)
{
  for (CP::list<T> &i : ls)
  {
    // skip empty sublists
    if (i.mHeader->next == i.mHeader)
      continue;

    // splice i at the end of *this
    auto first = i.mHeader->next;
    auto last = i.mHeader->prev;
    auto tail = this->mHeader->prev;
    this->mSize += i.size();

    tail->next = first;
    first->prev = tail;

    last->next = this->mHeader;
    this->mHeader->prev = last;

    // leave i empty
    i.mHeader->next = i.mHeader;
    i.mHeader->prev = i.mHeader;
    i.mSize = 0;
  }
}

#endif
