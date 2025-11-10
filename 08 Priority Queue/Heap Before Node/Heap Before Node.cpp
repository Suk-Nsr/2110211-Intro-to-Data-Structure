#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<int> answer;
    std::vector<int> nodeChild;
    std::queue<int> breadthFirstSearch;
    int totalNodes, selectedNode, times, index = 0;
    std::cin >> totalNodes >> selectedNode;
    
    nodeChild.push_back(selectedNode);
    breadthFirstSearch.push(selectedNode);

    while (selectedNode < totalNodes)
    {
        times = breadthFirstSearch.size();
        
        for (int i = 0; i < times; i++)
        {
            selectedNode = breadthFirstSearch.front();
            if (((selectedNode * 2) + 1) < totalNodes)
            {
                nodeChild.push_back(((selectedNode * 2) + 1));
                breadthFirstSearch.push(((selectedNode * 2) + 1));
            }
            if (((selectedNode * 2) + 2) < totalNodes)
            {
                nodeChild.push_back(((selectedNode * 2) + 2));
                breadthFirstSearch.push(((selectedNode * 2) + 2));
            }
            breadthFirstSearch.pop();
        }

        selectedNode = selectedNode * 2 + 1;
    }

    for (int i = 0; i < totalNodes; i++)
    {
        if (i == nodeChild[index])
        {
            index = std::min(static_cast<int>(nodeChild.size() - 1), index + 1);
            continue;
        }
        else
        {
            answer.push_back(i);
        }
    }

    std::cout << answer.size() << "\n";

    if (!(answer.empty()))
    {
        for (int i : answer)
        {
            std::cout << i << " ";
        }
    }
}