#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int level, int tmp)
{
    if (n == nullptr)
    {
        return;
    }
    
    my_recur(n->left, level, tmp + 1);
    my_recur(n->right, level, tmp + 1);

    if (tmp > level)
    {
        erase(n->data.first);
    }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::trim(int depth)
{
    if (depth == -1)
    {
        erase(this->mRoot->data.first);
    }

    my_recur(this->mRoot, depth, 0);
}

#endif
