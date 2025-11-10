#include <iostream>
#include <utility>
#include <set>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;
    std::set<int> somchaiGoods;
    std::map<int, int> somchaiSold;
    std::set<std::pair<int, int>> soldInTotal;

    for (int i = 0; i < N; i++)
    {
        int goods;
        std::cin >> goods;
        somchaiGoods.insert(goods);
    }

    for (int i = 0; i < M; i++)
    {
        int command;
        std::cin >> command;
        if (command == 1)
        {
            int goods, sold;
            std::cin >> goods >> sold;

            if (!somchaiGoods.count(goods)) {continue;}

            int oldCount = somchaiSold[goods];
            soldInTotal.erase({oldCount, goods});

            int newCount = oldCount + sold;
            somchaiSold[goods] = newCount;

            soldInTotal.insert({newCount, goods});
        } else {
            int sold;
            std::cin >> sold;
            auto it = soldInTotal.lower_bound({sold,0});
            if (it == soldInTotal.begin()) {
                std::cout << "NONE\n";
            } else {
                --it;
                std::cout << it->second << "\n";
            }

        }
    }
}