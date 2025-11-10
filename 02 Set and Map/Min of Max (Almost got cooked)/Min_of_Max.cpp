#include <iostream>
#include <utility>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> maxPower(m, 1);
    std::vector<int> receivedCard(n);
    std::set<std::pair<int, int>> minOfMax;

    for (int i = 0; i < m; i++)
    {
        minOfMax.insert(std::make_pair(1,i));
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        receivedCard[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        int type;
        std::cin >> type;
        if (receivedCard[i] > maxPower[type])
        {
            minOfMax.erase(std::make_pair(maxPower[type], type));
            maxPower[type] = receivedCard[i];
            minOfMax.insert(std::make_pair(maxPower[type], type));
        }
        std::cout << minOfMax.begin()->first << " ";
    }
}