#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
  // write your code here
  std::sort(data.begin(), data.end());
  CP::vector<T> temp;
  int dataIndex = 0;
  size_t size = this->size();

  for (int index = 0; index <= size; index++)
  {
    if (data[dataIndex].first == index)
    {
      temp.push_back(data[dataIndex].second);
      dataIndex++;
    }
    if (index < size)
    {
    temp.push_back(mData[index]);
    }
  }
  *this = temp;
}

#endif
