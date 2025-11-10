#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  size_t actual_pos = this->mSize - pos;
  ensureCapacity(mSize + 1);

  for (size_t i = mSize; i > actual_pos; i--)
  {
    this->mData[i] = this->mData[i - 1]; 
  }
  mData[actual_pos] = value;
  mSize++;
}

#endif