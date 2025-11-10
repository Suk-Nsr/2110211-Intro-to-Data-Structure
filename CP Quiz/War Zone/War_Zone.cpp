#include <iostream>
#include <utility>
#include <vector>
#include <set>

int main () {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    
    std::set<std::pair<int, int>> destroyedInterval;
    int N, M, destroyed = 0;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int L, R;
        std::cin >> L >> R;
        auto it = destroyedInterval.lower_bound({L, -1});

        if (it != destroyedInterval.begin())
        {
            auto prev = it;
            prev--;
            if (prev->second >= L)
            {
                it = prev;
            }
        }

        int newL = L, newR = R;
        std::vector<std::pair<int, int>> toErase;

        while (it != destroyedInterval.end() && it->first <= newR)
        {
            newL = std::min(newL, it->first);
            newR = std::max(newR, it->second);
            destroyed -= (it->second - it->first + 1);
            toErase.push_back(*it);
            it++;
        }

        for (auto x : toErase)
        {
            destroyedInterval.erase(x);
        }

        destroyed += (newR - newL + 1);
        destroyedInterval.insert({newL, newR});

        std::cout << N - destroyed << "\n";
    }
}