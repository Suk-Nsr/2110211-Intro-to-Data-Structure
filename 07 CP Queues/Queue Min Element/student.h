#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos, Comp comp) const
{
  T answer;

  for (size_t position : pos)
  {
    if (position < this->mSize)
    {
      answer = this->mData[(this->mFront + position) % this->mCap];
      break;
    }
  }

  for (size_t position : pos)
  {
    if (position < this->mSize)
    {
      if (comp(this->mData[(this->mFront + position) % this->mCap], answer))
      {
        answer = mData[(this->mFront + position) % this->mCap];
      }
    }
  }

  return answer;
}

#endif
