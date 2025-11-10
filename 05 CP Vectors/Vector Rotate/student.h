#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  CP::vector<T> temp;

  for (auto it = first; it < last; it++) {
    temp.push_back(*it);
  }

  int index = first - this->begin();

  for (size_t i = k; i < temp.size(); i++) {
    this->mData[index] = temp[i];
    index++;
  }

  for (size_t i = 0; i < k; i++) {
    this->mData[index] = temp[i];
    index++;
  }
}

#endif
