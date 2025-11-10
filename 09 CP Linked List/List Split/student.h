void splitList(list<T> &list1, list<T> &list2)
{
    if (this->empty())
    {
        return;
    }   
    else
    {
        size_t checkpoint = (this->mSize / 2);
        auto it1 = this->begin(), it2 = this->begin();

        for (size_t i = 0; i < this->mSize - checkpoint; ++i)
        {
            ++it1;
            ++it2;
        }

        --it1;

        list1.mHeader->prev->next = this->mHeader->next;
        this->mHeader->next->prev = list1.mHeader->prev;
        list1.mHeader->prev = it1.ptr;
        it1.ptr->next = list1.mHeader;

        list2.mHeader->prev->next = it2.ptr;
        it2.ptr->prev = list2.mHeader->prev;
        list2.mHeader->prev = this->mHeader->prev;
        this->mHeader->prev->next = list2.mHeader;

        this->mHeader->next = this->mHeader;
        this->mHeader->prev = this->mHeader;

        list1.mSize += (this->mSize - (this->mSize / 2));
        list2.mSize += this->mSize / 2;
        this->mSize = 0;
    }
}