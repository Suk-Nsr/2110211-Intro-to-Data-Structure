#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    size_t available_1 = this->mCap - this->mSize;
    size_t available_2 = other.mCap - other.mSize;
    if (available_1 == available_2) {return 0;}
    else if (available_1 > available_2) {return 1;}
    else {return -1;}
}

#endif
