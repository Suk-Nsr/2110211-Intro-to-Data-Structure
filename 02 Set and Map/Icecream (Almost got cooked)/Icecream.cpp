#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, start;
    std::cin >> n >> m >> start;
    std::map<int, int> decision;
    std::vector<int> moneyEachDay;

    for (int i = 0; i < n; i++)
    {
        int a, s;
        std::cin >> a >> s;
        decision[a] = s;
    }

    auto it_1 = decision.begin();
    int saveEachday = start, dayCounter = 0, totalMoney = 0;

    for (int i = 0; i < 100000; i++)
    {
        if (it_1 != decision.end())
        {
            if (dayCounter == it_1->first)
            {
                saveEachday = it_1->second;
                it_1++;
            }
        }
        totalMoney += saveEachday;
        moneyEachDay.push_back(totalMoney);
        dayCounter++;
    }

    for (int i = 0; i < m; i++)
    {
        int price, scam;
        std::cin >> price >> scam;
        if (price <= moneyEachDay[scam])
        {
            int day = std::lower_bound(moneyEachDay.begin(), moneyEachDay.end(), price) - moneyEachDay.begin();
            std::cout << day << " ";
        } else {
            price += moneyEachDay[scam];
            int day = std::lower_bound(moneyEachDay.begin(), moneyEachDay.end(), price) - moneyEachDay.begin();
            std::cout << day << " ";
        }
    }
}