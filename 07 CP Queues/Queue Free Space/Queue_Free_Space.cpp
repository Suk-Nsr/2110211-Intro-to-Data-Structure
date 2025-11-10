#include <iostream>

int main() {
    long long operation, mCap = 1, mSize = 0;
    std::cin >> operation;
    
    for (int i = 0; i < operation; i++)
    {
        int push_pop;
        std::cin >> push_pop;
        if (!push_pop)
        {
            int times;
            std::cin >> times;
            mSize += times;
            if (mSize > mCap)
            {
                while (mSize > mCap)
                {
                    mCap *= 2;
                }
            }
        } else {
            int times;
            std::cin >> times;
            mSize -= times;
        }
    }
    std::cout << mCap - mSize;
}