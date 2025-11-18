void shift(int k)
{
	if (this->mSize == 0 || this->mSize == 1)
	{
		return;
	}

	int timeToRotate = ((k % (int)this->mSize) + (int)this->mSize) % (int)this->mSize;
	auto it = this->begin();

	for (int i = 0; i < timeToRotate; ++i)
	{
		++it;
	}

	this->mHeader->next->prev = this->mHeader->prev;
	this->mHeader->prev->next = this->mHeader->next;
	this->mHeader->next = it.ptr;
	this->mHeader->prev = it.ptr->prev;
	it.ptr->prev->next = this->mHeader;
	it.ptr->prev = this->mHeader;
}