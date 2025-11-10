#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const
{
  // write your code here
  //  if you use std::vector, your score will be half (grader will report score BEFORE halving)
  size_t n = std::min(this->size(), other.size());
  for (size_t i = 0; i < n; ++i) {
    if (this->mData[i] < other.mData[i]) return true;
    if (this->mData[i] > other.mData[i]) return false;
  }
  return this->size() < other.size();
}

#endif
