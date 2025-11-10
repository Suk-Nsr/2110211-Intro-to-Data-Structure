#include <iostream>
#include <vector>
#include <stack>

int main()
{
    long long nodeAmount, k_ary;
    int nodeWantToFind;
    std::cin >> nodeAmount >> k_ary >> nodeWantToFind;
    
    for (int i = 0; i < nodeWantToFind; ++i)
    {
        std::vector<long long> output;
        std::stack<long long> tempEnding;
        int startingNode, endingNode;

        std::cin >> startingNode >> endingNode;

        output.push_back(startingNode);
        tempEnding.push(endingNode);

        while (startingNode != endingNode)
        {
            if (startingNode > endingNode)
            {
                startingNode = (startingNode - 1) / k_ary;
                output.push_back(startingNode);
            }
            else
            {
                endingNode = (endingNode - 1) / k_ary;
                tempEnding.push(endingNode);
            }
        }

        tempEnding.pop();

        while (!(tempEnding.empty()))
        {
            output.push_back(tempEnding.top());
            tempEnding.pop();
        }

        std::cout << output.size() - 1 << "\n";

        for (int j = 0; j < output.size() - 1; ++j)
        {
            std::cout << output[j] << " -> ";
        }

        std::cout << output[output.size() - 1] << "\n";
    }
}