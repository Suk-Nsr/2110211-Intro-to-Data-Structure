#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to)
{
    if (static_cast<int>(from) >= this->mSize / 2)
    {
        for (size_t i = to + 1; i < this->mSize; i++)
        {
            this->mData[(this->mFront + i + this->mCap - (to - from + 1)) % this->mCap] = this->mData[(this->mFront + i) % this->mCap];
        }
    }
    else
    {
        for (size_t i = from; i > 0; i--)
        {
            this->mData[(this->mFront + i + to - from) % this->mCap] = this->mData[(this->mFront + i + this->mCap - 1) % this->mCap];
        }
        this->mFront = (this->mFront + (to - from + 1)) % this->mCap;
    }
    this->mSize = this->mSize - (to - from + 1);
    return;
}
#endif