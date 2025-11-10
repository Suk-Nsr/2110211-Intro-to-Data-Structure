#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m)
{
  // write your code here
  if (m == 0) return false;
  if (a < begin() || b < begin()) return false;
  if (a + m > end() || b + m > end()) return false;

  bool no_overlap = (a + m <= b) || (b + m <= a);
  if (!no_overlap) return false;

  for (size_t i = 0; i < m; i++)
  {
    std::swap(mData[a - this->begin() + i], mData[b - this->begin() + i]);
  }

  return true;
}
  


#endif
