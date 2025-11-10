#include <queue>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> indexArray;
    std::queue<int> process;
    int nodes, pairs, index;
    std::cin >> nodes >> pairs;

    for (int i = 0; i < nodes; i++)
    {
        indexArray.push_back(i);
    }

    for (int i = 0; i < pairs; i++)
    {
        bool founded = false;
        int indexOfA, indexOfB;
        std::cin >> indexOfA >> indexOfB;

        if (indexOfA == indexOfB)
        {
            std::cout << "a and b are the same node\n";
            founded = true;
        }

        process.push(indexOfA);
        index = indexOfA;

        while (index < indexArray.size() && !founded)
        {
            int times = process.size();

            for (int j = 0; j < times; j++)
            {
                index = process.front();

                if (((index * 2) + 1) < indexArray.size())
                {
                    process.push(((index * 2) + 1));
                    if (((index * 2) + 1) == indexOfB)
                    {
                        std::cout << "a is an ancestor of b\n";
                        founded = true;
                        break;
                    }
                }

                if (((index * 2) + 2) < indexArray.size())
                {
                    process.push(((index * 2) + 2));
                    if (((index * 2) + 2) == indexOfB)
                    {
                        std::cout << "a is an ancestor of b\n";
                        founded = true;
                        break;
                    }
                }

                process.pop();
            }

            index = index * 2 + 1;
        }

        while (!(process.empty()))
        {
            process.pop();
        }

        process.push(indexOfB);
        index = indexOfB;

        while (index < indexArray.size() && !founded)
        {
            int times = process.size();

            for (int j = 0; j < times; j++)
            {
                index = process.front();

                if (((index * 2) + 1) < indexArray.size())
                {
                    process.push(((index * 2) + 1));
                    if (((index * 2) + 1) == indexOfA)
                    {
                        std::cout << "b is an ancestor of a\n";
                        founded = true;
                        break;
                    }
                }

                if (((index * 2) + 2) < indexArray.size())
                {
                    process.push(((index * 2) + 2));
                    if (((index * 2) + 2) == indexOfA)
                    {
                        std::cout << "b is an ancestor of a\n";
                        founded = true;
                        break;
                    }
                }

                process.pop();
            }

            index = index * 2 + 1;
        }

        while (!(process.empty()))
        {
            process.pop();
        }

        if (!founded)
        {
            std::cout << "a and b are not related\n";
        }
    }
}