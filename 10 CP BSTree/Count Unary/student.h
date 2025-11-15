#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *ptr) const
{
  if (ptr == nullptr)
  {
    return 0;
  }
  else if (ptr->left == nullptr && ptr->right == nullptr)
  {
    return 0;
  }
  else if (ptr->left == nullptr)
  {
    return process(ptr->right) + 1;
  }
  else if (ptr->right == nullptr)
  {
    return process(ptr->left) + 1;
  }
  return process(ptr->left) + process(ptr->right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::count_unary() const
{
  return process(this->mRoot);
}

#endif
