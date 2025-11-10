#include <iostream>

int main() {
    int occupied, mData = 1;
    std::cin >> occupied;

    while (mData < occupied) {
        mData *= 2;
    }

    std::cout << mData - occupied;
}