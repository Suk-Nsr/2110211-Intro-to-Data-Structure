#include <iostream>
#include <utility>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<std::pair<int, int>> occupied;

    for (int i = 0; i < n; i++)
    {
        int command;
        std::cin >> command;

        if (command == 2) {std::cout << occupied.size() << "\n";}

        if (command == 1)
        {
            int first, last;
            std::cin >> first >> last;
            int left = first, right = last;
            auto it = occupied.lower_bound({left,0});

            if (it != occupied.begin())
            {
                auto previous = prev(it);
                if (previous->second >= left - 1)
                {
                    left = std::min(previous->first, left);
                    right = std::max(previous->second, right);
                    it = occupied.erase(previous);
                }
            }

            while (it != occupied.end() && it->first <= right + 1)
            {
                left = std::min(it->first, left);
                right = std::max(it->second, right);
                it = occupied.erase(it);
            }

            occupied.insert({left,right});
        }
    }
}