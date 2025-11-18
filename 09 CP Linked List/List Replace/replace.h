void replace(const T &x, list<T> &y)
{
  auto it = this->begin();

  while (it != this->end())
  {
    if (it.ptr->data == x)
    {
      auto insertPos = it;

      for (auto data : y)
      {
        insert(insertPos, data);
      }

      it = erase(it);
    }
    else
    {
      ++it;
    }
  }
}
