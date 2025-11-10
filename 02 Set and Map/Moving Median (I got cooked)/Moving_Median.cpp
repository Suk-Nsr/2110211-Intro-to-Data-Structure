#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::queue<std::pair<int, std::multiset<int>::iterator>> tempErase;
    std::multiset<int> toFindMedian;
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        std::multiset<int>::iterator A = toFindMedian.insert(temp);
        tempErase.push(std::make_pair(temp, A));

        if (toFindMedian.size() == (m + 1))
        {
            std::multiset<int>::iterator median = next(toFindMedian.begin(), (m / 2));
            std::cout << *median << " ";
            toFindMedian.erase(tempErase.front().second);
            tempErase.pop();
        }
    }
}