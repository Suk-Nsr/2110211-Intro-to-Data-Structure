#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  size_t answer = 0;
  for (size_t i = 0; i < this->mSize; i++)
  {
    if (mLess(this->mData[pos], this->mData[i]))
    {
      answer++;
    }
  }
  return answer;
}

#endif
