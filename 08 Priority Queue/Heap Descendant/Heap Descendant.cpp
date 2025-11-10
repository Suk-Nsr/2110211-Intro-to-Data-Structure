#include <queue>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> indexArray;
    std::vector<int> answer;
    std::queue<int> process;
    int nodes, descendantOf, index, times;
    std::cin >> nodes >> descendantOf;

    for (int i = 0; i < nodes; i++)
    {
        indexArray.push_back(i);
    }

    process.push(descendantOf);
    answer.push_back(descendantOf);

    while (index < indexArray.size())
    {
        times = process.size();
        for (int i = 0; i < times; i++)
        {
            index = process.front();
            if (((index * 2) + 1) < indexArray.size())
            {
                answer.push_back(((index * 2) + 1));
                process.push(((index * 2) + 1));
            }
            if (((index * 2) + 2) < indexArray.size())
            {
                answer.push_back(((index * 2) + 2));
                process.push(((index * 2) + 2));
            }
            process.pop();
        }
        index = index * 2 + 1;
    }

    std::cout << answer.size() << "\n";

    for (auto x : answer)
    {
        std::cout << x << " ";
    }
}