#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  for (size_t i = mFront; i < (mFront + k); i++)
  {
    res.push_back(mData[i % mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  this->mCap = to - from;
  this->mSize = to - from;
  this->mFront = 0;
  int index = 0;
  for (iterator i = from; i < to; i++)
  {
    this->mData[index] = *i;
    index++;
  }
}

#endif
