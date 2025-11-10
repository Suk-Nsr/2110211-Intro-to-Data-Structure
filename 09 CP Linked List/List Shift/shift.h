void shift(int k)
{
	if (k == 0 || this->mSize <= 1)
	{
		return;
	}

	auto it = this->mHeader->next;
	int n = this->mSize;
	int shifted = ((k % n) + n) % n;

	while (shifted--)
	{
		it = it->next;
	}

	this->mHeader->next->prev = this->mHeader->prev;
	this->mHeader->prev->next = this->mHeader->next;
	this->mHeader->next = it;
	this->mHeader->prev = it->prev;
	it->prev->next = this->mHeader;
	it->prev = this->mHeader;
}