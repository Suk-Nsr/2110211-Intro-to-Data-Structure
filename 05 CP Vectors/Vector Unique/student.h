#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>

template <typename T>
void CP::vector<T>::uniq() {
  std::set<T> seen;
  int i = 0;

  for (int j = 0; j < mSize; j++) {
    if (seen.find(mData[j]) == seen.end()) {
      seen.insert(mData[j]);
      mData[i] = mData[j];
      i++;
    }
  }

  mSize = i;
}

#endif
