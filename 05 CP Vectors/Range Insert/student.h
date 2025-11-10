#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  CP::vector<T> temp;

  for (int i = 0; i < position - this->begin(); i++) {
    temp.push_back(this->mData[i]);
  }

  for (auto it = first; it < last; it++) {
    temp.push_back(*it);
  }

  for (auto it = position; it < this->end(); it++) {
    temp.push_back(*it);
  }

  *this = temp;
}

#endif
