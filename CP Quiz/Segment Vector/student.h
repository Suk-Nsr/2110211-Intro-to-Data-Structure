#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "segmented_vector.h"
template <typename T>
CP::SegmentedVector<T>::~SegmentedVector()
{
    for (int i = 0; i < this->mSize; i++)
    {
        for (int j = 0; j < this->blockSize; j++)
        {
            delete mData[i][j];
        }
        delete mData[i];
    }
}
template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity)
{
    if (capacity > this->mCap)
    {
        
    }
}
template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T& element)
{
    // TODO: Write your code here
}
template <typename T>
T& CP::SegmentedVector<T>::operator[](int index) const
{
    // TODO: Write your code here
}
#endif