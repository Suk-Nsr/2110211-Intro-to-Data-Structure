#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::map<int,int> setRange;
    std::vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        int lower, upper;
        std::cin >> lower >> upper;
        setRange[upper] = lower;
    }

    for (int i = 0; i < m; i++)
    {
        int number ;
        std::cin >> number;
        auto it = setRange.lower_bound(number);
        if ((it == setRange.end()) || it->second > number)
        {
            answer.push_back(0);
        } else {
            answer.push_back(1);
        }
    }

    for (auto x : answer)
    {
        std::cout << x << " ";
    }
}