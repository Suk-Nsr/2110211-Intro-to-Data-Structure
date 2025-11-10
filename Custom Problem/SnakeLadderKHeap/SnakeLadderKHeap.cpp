#include <iostream>
#include <utility>
#include <set>

int main()
{
    std::set<int> startPos, trapPos;
    std::set<std::pair<int, int>> answer;
    int nodeAmount, K_ary, startAmount, diceValue, trapAmount;
    std::cin >> nodeAmount >> K_ary >> startAmount >> diceValue;

    for (int i = 0; i < startAmount; ++i)
    {
        int startNode;
        std::cin >> startNode;
        startPos.insert(startNode); 
    }

    std::cin >> trapAmount;

    for (int i = 0; i < trapAmount; ++i)
    {
        int trapNode;
        std::cin >> trapNode;
        trapPos.insert(trapNode);
    }

    for (int i : startPos)
    {
        int temp_start = i, temp_stop = i, tempDice = diceValue;

        while (trapPos.find(temp_stop) == trapPos.end() && tempDice)
        {
            temp_stop = (temp_stop - 1) / K_ary;
            --tempDice;
        }

        if (trapPos.find(temp_stop) != trapPos.end())
        {
            continue;
        }
        else
        {
            answer.insert(std::make_pair(temp_start, temp_stop));
        }
    }

    std::cout << answer.size() << "\n";

    for (std::pair<int, int> i : answer)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}