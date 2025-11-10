#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  std::vector<T> shifted;
  std::vector<T> inserted;

  for (int i = 0; i < k; i++)
  {
    shifted.push_back(this->top());
    this->pop();
  }

  while (m > 0 && !(s2.empty()))
  {
    inserted.push_back(s2.top());
    s2.pop();
    m--;
  }

  for (int i = inserted.size(); i > 0; i--)
  {
    this->push(inserted[i - 1]);
  }

  for (int i = shifted.size(); i > 0; i--)
  {
    this->push(shifted[i - 1]);
  }
}
#endif
