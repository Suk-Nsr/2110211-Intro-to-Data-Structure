#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val)
{
  // your code here
  CP::map_bst<KeyT, MappedT, CompareT> result;
  node *ptr = this->mRoot;
  node *parentLeft = nullptr;
  node *parentRight = nullptr;
  bool resultTreeOrNot = true;

  while (ptr != nullptr)
  {
    if (resultTreeOrNot)
    {
      if (ptr->data.first >= val)
      {
        parentLeft = ptr->parent;
        this->child_link(parentLeft, val) = nullptr;
        result.child_link(parentRight, val) = ptr;
        ptr->parent = parentRight;
        ptr = ptr->left;
        resultTreeOrNot = false;
      }
      else
      {
        ptr = ptr->right;
      }
    }
    else
    {
      if (ptr->data.first < val)
      {
        parentRight = ptr->parent;

        if (parentRight != nullptr)
        {
          parentRight->left = nullptr;
        }

        this->child_link(parentLeft, val) = ptr;
        ptr->parent = parentLeft;
        ptr = ptr->right;
        resultTreeOrNot = true;
      }
      else
      {
        ptr = ptr->left;
      }
    }
  }
  return result;
}

#endif
