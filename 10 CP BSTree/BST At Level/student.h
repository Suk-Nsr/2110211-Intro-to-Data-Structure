#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, size_t level, size_t tmp, std::vector<KeyT> &v)
{
  if (n == nullptr)
  {
    return;
  }
  else if (tmp > level)
  {
    return;
  }
  else if (tmp == level)
  {
    v.push_back(n->data.first);
  }
  my_recur(n->right, level, tmp + 1, v);
  my_recur(n->left, level, tmp + 1, v);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT, MappedT, CompareT>::at_level(size_t level)
{
  std::vector<KeyT> keys;

  my_recur(this->mRoot, level, 0, keys);

  return keys;
}

#endif
