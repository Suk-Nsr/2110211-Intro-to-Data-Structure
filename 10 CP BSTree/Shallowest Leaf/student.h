#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::shallowest_leaf(node *n)
{
  if (n == nullptr)
  {
    return 0;
  }
  if (n->left == nullptr && n->right == nullptr)
  {
    return 0;
  }
  if (n->left == nullptr)
  {
    return shallowest_leaf(n->right) + 1;
  }
  if (n->right == nullptr)
  {
    return shallowest_leaf(n->left) + 1;
  }
  return std::min(shallowest_leaf(n->left) + 1, shallowest_leaf(n->right) + 1);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::shallowest_leaf()
{
  if (this->mRoot != nullptr)
  {
    return shallowest_leaf(this->mRoot);
  }
  else
  {
    return -1;
  }
}

#endif
