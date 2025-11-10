#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  std::vector<int> times(k, static_cast<int>(this->size() / k));
  CP::stack<T> copied(*this);

  for (int i = 0; i < this->size() % k; i++)
  {
    times[i]++;
  }

  std::vector<std::vector<T>> output(k);

  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < times[i]; j++)
    {
      output[i].push_back(copied.top());
      copied.pop();
    }
    //std::reverse(output[i].begin(), output[i].end());
  }

  return output;

}
#endif
