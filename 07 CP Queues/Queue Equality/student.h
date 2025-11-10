#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const
{
  if (this->mSize != other.mSize)
    return false;
  for (int i = 0; i < this->mSize; i++)
  {
    if (this->mData[(this->mFront + i) % this->mCap] != other.mData[(other.mFront + i) % other.mCap])
      return false;
  }
  return true;
}

#endif
