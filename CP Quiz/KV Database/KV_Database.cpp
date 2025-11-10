#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<int, std::map<int, int>> dataHistory;

    int Q, version = 0;
    std::cin >> Q;

    while (Q--)
    {
        std::string operation;
        int index, value_version;
        std::cin >> operation >> index >> value_version;

        if (operation == "U")
        {
            version++;
            dataHistory[index][version] = value_version;
        }
        else
        {
            auto it_1 = dataHistory.find(index);
            if (it_1 == dataHistory.end())
            {
                std::cout << "-1\n";
            }
            else
            {
                auto it_2 = dataHistory[index].upper_bound(value_version);
                if (it_2 == dataHistory[index].end())
                {
                    it_2--;
                    std::cout << it_2->second << "\n";
                }
                else if (it_2 == dataHistory[index].begin())
                {
                    std::cout << "-1\n";
                }
                else
                {
                    it_2--;
                    std::cout << it_2->second << "\n";
                }
            }
        }
    }
}