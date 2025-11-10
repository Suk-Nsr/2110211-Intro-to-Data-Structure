#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {

  ensureCapacity(mSize * 2);
  size_t index = 1;

  for (size_t i = mSize; i-- > 0;) {
    mData[i + index] = mData[i];
    index += 2;
  }

  mSize *= 2;
}

#endif
