#include <iostream>
#include <stack>
#include <set>

int main()
{
    int nodeAmount;
    std::set<int> nodeData;
    std::set<int> answer;

    std::cin >> nodeAmount;

    for (int i = 0; i < nodeAmount; ++i)
    {
        int nodeIndex;
        std::cin >> nodeIndex;
        nodeData.insert(nodeIndex);
    }

    for (auto i : nodeData)
    {
        std::stack<int> path;

        while (i > 0)
        {
            i = (i - 1) / 2;
            path.push(i);
        }

        while (!(path.empty()))
        {
            if (nodeData.find(path.top()) != nodeData.end())
            {
                answer.insert(path.top());
                break;
            }
            path.pop();
        }
    }

    std::cout << answer.size();
}