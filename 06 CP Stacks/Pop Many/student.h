#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  mSize -= std::min(K,mSize);
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  size_t times = mSize - std::min(K,mSize);
  std::stack<T> removed;
  for (size_t i = times; i < mSize; i++)
  {
    removed.push(mData[i]);
  }
  mSize = times;
  return removed;
}

#endif
