#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <algorithm>
#include <vector>
#include <map>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs)
{
  // Write code here
  std::map<int, int> repeatOrNot;

  for (auto it : itrs)
  {
    if (repeatOrNot.find(*it) == repeatOrNot.end())
    {
      repeatOrNot[*it] = 1;
    }
    else
    {
      repeatOrNot[*it]++;
    }
  }

  std::vector<CP::vector<T>::iterator> its;

  for (auto it : itrs)
  {
    its.push_back(it);
  }

  std::sort(its.begin(), its.end(), std::greater<CP::vector<T>::iterator>());

  for (auto it : its)
  {
    if (repeatOrNot[*it] == 1)
    {
      continue;
    }
    else
    {
      repeatOrNot[*it]--;
      this->erase(it);
    }
  }
}

#endif
