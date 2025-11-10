#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  CP::queue<T> copied;
  copied = *this;

  if (k > static_cast<int>(this->mSize))
  {
    k = static_cast<int>(this->mSize);
  }

  for (int i = 0; i < k; i++)
  {
    res.push_back(copied.front());
    copied.pop();
  }

  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  this->mCap = 1;
  this->mSize = 0;
  this->mFront = 0;
  this->mData = new T[mCap]();

  for (auto i = from; i != to; i++)
  {
    this->ensureCapacity(this->mSize+1);
    this->mData[(this->mSize + this->mFront) % this->mCap] = *i;
    this->mSize++;
  }
}

#endif
