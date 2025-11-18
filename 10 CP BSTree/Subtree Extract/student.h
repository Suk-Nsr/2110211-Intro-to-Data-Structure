#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n)
{
  if (n == nullptr)
  {
    return 0;
  }
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(map_bst<KeyT, MappedT, CompareT> &left, map_bst<KeyT, MappedT, CompareT> &right)
{
  if (this->mRoot == nullptr)
  {
    return std::pair<KeyT, MappedT>();
  }
  else
  {
    left.clear();
    right.clear();
    left.mRoot = this->mRoot->left;
    left.mSize = process(left.mRoot);
    right.mRoot = this->mRoot->right;
    right.mSize = process(right.mRoot);
    this->mSize = 1;
    this->mRoot->left = nullptr;
    this->mRoot->right = nullptr;    
    return this->mRoot->data;
  }
}

#endif
