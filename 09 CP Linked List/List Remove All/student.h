#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  CP::list<T>::iterator it = this->begin();
  while (it != this->end())
  {
    CP::list<T>::iterator nextNode(it.ptr->next);
    if (it.ptr->data == value)
    {
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      this->mSize--;
    }
    it = nextNode;
  }
}

#endif
