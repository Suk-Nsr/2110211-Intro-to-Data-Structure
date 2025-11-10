#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {

  if (this->mSize != other.mSize)
  {
    return false;
  }

  CP::priority_queue<T,Comp>A(*this);
  CP::priority_queue<T,Comp>B(other);

  while (!(A.empty()))
  {
    if (A.top() != B.top())
    {
      return false;
    }
    else
    {
      A.pop();
      B.pop();
    }
  }

  return true;
}

#endif
