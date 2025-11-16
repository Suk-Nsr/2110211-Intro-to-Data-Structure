#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux)
{
    if (n == nullptr)
    {
        return -1;
    }
    
    int maxLeft = my_recur(n->left, aux) + 1;
    int maxRight = my_recur(n->right, aux) + 1;

    aux = std::max(aux, maxLeft + maxRight);

    return std::max(maxLeft, maxRight);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance()
{
    int max = -1;
    my_recur(this->mRoot, max);
    return max;
}

#endif
