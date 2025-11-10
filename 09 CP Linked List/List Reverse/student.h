#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b)
{
  if (this->empty() || a == b)
  {
    return a;
  }

  --b;

  auto it(a);

  while (a != b)
  {
    std::swap(*a,*b);
    ++a;
    if (a == b)
    {
      break;
    }
    --b;
  }
  return it;
}

#endif
