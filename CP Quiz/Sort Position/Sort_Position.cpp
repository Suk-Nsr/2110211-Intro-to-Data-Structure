#include <iostream>
#include <utility>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector <int> index(n);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> sorted;
    
    for (int i = 1; i <= n; i++)
    {
        int number;
        std::cin >> number;
        sorted.push({number,i});
    }

    int position = 1;

    for (int i = 0; i < n; i++)
    {
        int data = sorted.top().second - 1;
        index[data] = position;
        sorted.pop();
        position++;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << index[i] << " ";
    }
}