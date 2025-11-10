void replace(const T &x, list<T> &y)
{
  auto it = this->begin();

  while (it != this->end())
  {
    if (*it == x)
    {
        auto insertPos = it;

        for (auto& item : y)
        {
            insert(insertPos, item);
        }

        it = this->erase(it);
    }
    else
    {
        ++it;
    }
  }
}
