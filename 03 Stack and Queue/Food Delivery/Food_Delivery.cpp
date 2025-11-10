#include <iostream>
#include <utility>
#include <vector>
#include <queue>

int main() {
    std::vector<int> target;
    std::queue<int> foodPlaThong, dotMan;
    std::vector<std::pair<int, int>> order2price;
    int n, m, money = 0, no = 1;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        std::cin >> temp;
        target.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int doOrGet;
        std::cin >> doOrGet;
        if (doOrGet == 1)
        {
            int whichApps, price;
            std::cin >> whichApps >> price;
            if (whichApps == 1)
            {
                foodPlaThong.push(price);
            } else {
                dotMan.push(price);
            }
        } else {
            if (foodPlaThong.empty() && !(dotMan.empty()))
            {
                money += dotMan.front();
                order2price.push_back({money, no});
                dotMan.pop();
                no++;
            } else if (!(foodPlaThong.empty()) && dotMan.empty())
            {
                money += foodPlaThong.front();
                order2price.push_back({money, no});
                foodPlaThong.pop();
                no++;
            } else {
                if (foodPlaThong.front() > dotMan.front())
                {
                    money += dotMan.front();
                    order2price.push_back({money, no});
                    dotMan.pop();
                    no++;
                } else {
                    money += foodPlaThong.front();
                    order2price.push_back({money, no});
                    foodPlaThong.pop();
                    no++;
                }
            }
        }
    }

    for (auto x :target)
    {
        std::pair<int ,int> temp = {x, 0};
        auto it = std::lower_bound(order2price.begin(), order2price.end(), temp);
        if (it == order2price.end())
        {
            std::cout << "-1 ";
        } else {
            std::cout << it->second << " ";
        }
    }
}