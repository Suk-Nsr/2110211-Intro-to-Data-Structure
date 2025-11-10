#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> speedHistory;
    std::vector<int> brakeHistoryTimes;
    std::vector<std::pair<int,int>> brakeHistory;

    for (int i = 0; i < n; i++)
    {
        std::pair<int,int> input;
        std::cin >> input.first >> input.second;
        brakeHistory.push_back(input);
    }

    std::sort(brakeHistory.begin(), brakeHistory.end());
    int temp = 0;
    speedHistory.push_back(k);

    for (int i = 0; i < brakeHistory.size(); i++)
    {
        if (k < 0) k = 0;
        brakeHistoryTimes.push_back(brakeHistory[i].first - 1);

        for (int j = 0; j < brakeHistory[i].first - temp; j++)
        {
            if (speedHistory.back() == k) break;
            speedHistory.push_back(k);
        }

        k = k - brakeHistory[i].second;
        temp = brakeHistory[i].first;
    }

    std::vector<int> reverseSpeedHistory;
    reverseSpeedHistory = speedHistory;
    std::sort(reverseSpeedHistory.begin(), reverseSpeedHistory.end());

    for (int i = 0; i < m; i++)
    {
        int selector, value;
        std::cin >> selector >> value;
        if (selector == 1)
        {
            auto it = std::lower_bound(brakeHistoryTimes.begin(), brakeHistoryTimes.end(), value);
            auto index = it - brakeHistoryTimes.begin();
            if (index >= 0 && index < speedHistory.size()) {
                std::cout << speedHistory[index] << "\n";
            } else {
                std::cout << "0\n";
            }
        } else {
            auto it = std::lower_bound(speedHistory.rbegin(), speedHistory.rend(), value);
            auto index = it.base() - speedHistory.begin() - 1;
            if (index < 0 || index >= brakeHistoryTimes.size()) {
                std::cout << "0\n";
            } else {
                std::cout << brakeHistoryTimes[index] + 1 << "\n";
            }
        }
    }
}