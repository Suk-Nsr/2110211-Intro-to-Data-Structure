#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  CP::vector<T> temp;
  int posIndex = 0;

  for (int i = 0; i < this->size(); i++)
  {
    if (posIndex < pos.size())
    {
      if (pos[posIndex] == i)
      {
        posIndex++;
        continue;
      }
      else
      {
        temp.push_back(this->mData[i]);
      }
    }
    else
    {
      temp.push_back(this->mData[i]);
    }
  }

  std::swap(this->mData,temp.mData);
  std::swap(this->mSize,temp.mSize);
  std::swap(this->mCap,temp.mCap);
}

#endif
