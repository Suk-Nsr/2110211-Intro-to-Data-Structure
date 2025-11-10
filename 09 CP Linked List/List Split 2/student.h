#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  CP::list<T> result;

  if (pos > this->mSize - 1)
  {
    return result;
  }

  result.mHeader->next = it.ptr;
  result.mHeader->prev = this->mHeader->prev;
  this->mHeader->prev->next = result.mHeader;
  it.ptr->prev->next = this->mHeader;
  this->mHeader->prev = it.ptr->prev;
  it.ptr->prev = result.mHeader;
  result.mSize = this->mSize - pos;
  this->mSize = pos;

  return result;
}

#endif
