#include <iostream>

int main()
{
    long long nodeAmount, k_ary, firstNode, secondNode;
    int nodeInput;

    std::cin >> nodeAmount >> k_ary >> nodeInput >> firstNode;

    for (int i = 1; i < nodeInput; ++i)
    {
        std::cin >> secondNode;

        while (firstNode != secondNode)
        {
            if (firstNode < secondNode)
            {
                secondNode = (secondNode - 1) / k_ary;
            }
            else
            {
                firstNode = (firstNode - 1) / k_ary;
            }
        }
    }

    std::cout << firstNode;
}