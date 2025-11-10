#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <utility>
#include <vector>
#include <map>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges)
{

  std::map<int, int> indexRange;

  for (auto range : ranges)
  {
    int left = range.first - begin();
    int right = range.second - begin();
    auto it = indexRange.lower_bound(left);

    if (it != indexRange.begin())
    {
      auto previous = std::prev(it);

      if (previous->second >= left)
      {
        left = std::min(previous->first, left);
        right = std::max(previous->second, right);
        it = indexRange.erase(previous);
      }
    }

    while (it != indexRange.end() && it->first <= right)
    {
      left = std::min(left, it->first);
      right = std::max(right, it->second);
      it = indexRange.erase(it);
    }

    indexRange[left] = right;
  }

  std::vector<std::pair<int, int>> mergedRange(indexRange.begin(), indexRange.end());
  for (int i = mergedRange.size(); i-- > 0;)
  {
    int left = mergedRange[i].first;
    int right = mergedRange[i].second;
    for (int j = right - 1; j >= left; --j)
    {
      erase(begin() + j);
    }
  }
}

#endif
