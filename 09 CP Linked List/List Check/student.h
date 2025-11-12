#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check()
{
  if (this->mHeader == NULL)
  {
    return false;
  }
  auto node = this->mHeader->next;
  if (node == NULL)
  {
    return false;
  }
  if (node->prev != this->mHeader)
  {
    return false;
  }

  for (int i = 0; i < this->mSize; ++i)
  {
    if (node == NULL)
    {
      return false;
    }
    if (node->next == NULL)
    {
      return false;
    }
    if (node->next->prev == NULL)
    {
      return false;
    }
    if (node->next->prev != node)
    {
      return false;
    }
    node = node->next;
  }
  return node == this->mHeader;
}

#endif
