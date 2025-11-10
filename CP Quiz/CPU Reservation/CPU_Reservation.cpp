#include <iostream>
#include <utility>
#include <vector>
#include <set>

int main() {
    int N;
    std::cin >> N;
    std::vector <int> answer;
    std::set<std::pair<int, int>> occupied;

    for (int i = 1; i <= N; i++)
    {
        int start, stop;
        std::cin >> start >> stop;
        auto it = occupied.lower_bound({stop,0});
        if (it != occupied.begin())
        {
            auto prev = it;
            prev--;
            if ((it->first != stop) && (prev->second < start))
            {
                occupied.insert({start,stop});
                answer.push_back(i);
            }
        } else {
            if (it->first != stop)
            {
                occupied.insert({start,stop});
                answer.push_back(i);
            }
        }
    }

    for (int x : answer)
    {
        std::cout << x << " ";
    }
}