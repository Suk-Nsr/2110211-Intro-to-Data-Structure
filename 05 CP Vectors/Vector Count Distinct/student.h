#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    std::set<T> count;

    while (a != b)
    {
        count.insert(*a);
        ++a;
    }

    return count.size();
}

#endif