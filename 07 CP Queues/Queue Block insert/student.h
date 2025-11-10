#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	this->ensureCapacity(this->mSize + m);
	
	if (p >= this->mSize / 2)
	{
		for (size_t i = this->mSize; i > p; i--)
		{
			this->mData[(mFront + i + m - 1) % mCap] = this->mData[(mFront + i - 1) % mCap];
		}
		
		for (size_t i = 0; i < m; i++)
		{
			this->mData[(mFront + p + i) % mCap] = element;
		}
	}
	else
	{
		mFront = (mFront + mCap - m) % mCap;

		for (size_t i = 0; i < p; i++)
		{
			this->mData[(mFront + i) % mCap] = this->mData[(mFront + i + m) % mCap];
		}
		
		for (size_t i = 0; i < m; i++)
		{
			this->mData[(mFront + p + i) % mCap] = element;
		}
	}

	this->mSize += m;
}

#endif
