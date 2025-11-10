#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    auto newData = new T[mSize];
    for (int i = 0; i < mSize; i++)
    {
        newData[i] = mData[i];
    }
    delete[] mData;
    mData = newData;
    mCap = mSize;
}

#endif