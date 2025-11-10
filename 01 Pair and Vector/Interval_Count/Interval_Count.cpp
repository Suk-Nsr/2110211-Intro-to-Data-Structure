#include <iostream>
#include <vector>
#include <algorithm>

int n, m, k = 0;

int main() {
    std::cin >> n >> m >> k;
    std::vector<int> checkList;
    std::vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        std::cin >> temp;
        checkList.push_back(temp);
    }

    std::sort(checkList.begin(),checkList.end());

    for (int i = 0; i < m; i++)
    {
        int temp = 0, lower = 0, upper = 0;
        std::cin >> temp;
        lower = temp - k;
        upper = temp + k;
        auto lower_it = std::lower_bound(checkList.begin(),checkList.end(),lower);
        auto upper_it = std::lower_bound(checkList.begin(),checkList.end(),upper);
        if ((*upper_it > upper) || (upper_it == checkList.end()))
        {
            upper_it--;
        }
        answer.push_back((upper_it - lower_it) + 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (i == (m - 1))
        {
            std::cout << answer[i];
        } else {
            std::cout << answer[i] << " ";
        }
    }
}