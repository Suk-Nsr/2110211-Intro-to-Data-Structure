void splitList(list<T> &list1, list<T> &list2)
{
    if (this->mSize > 0)
    {
        int middlePos = (this->mSize + 1) / 2;
        auto it = this->begin();

        for (int i = 0; i < middlePos; ++i)
        {
            ++it;
        }

        list1.mHeader->prev->next = this->mHeader->next;
        it.ptr->prev->next = list1.mHeader;
        this->mHeader->next->prev = list1.mHeader;
        list1.mHeader->prev = it.ptr->prev;

        list2.mHeader->prev->next = it.ptr;
        this->mHeader->prev->next = list2.mHeader;
        it.ptr->prev = list2.mHeader->prev;
        list2.mHeader->prev = this->mHeader->prev;

        this->mHeader->next = this->mHeader;
        this->mHeader->prev = this->mHeader;

        list1.mSize += middlePos;
        list2.mSize += (this->mSize - middlePos);
        this->mSize = 0;
    }
}