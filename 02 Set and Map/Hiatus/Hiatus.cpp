#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;
    std::vector<int> yearPublished;
    std::cin >> n >> m;
    std::map<int,std::vector<int>> published;

    for (int i = 0; i < n; i++)
    {
        int year, month;
        std::cin >> year >> month;
        published[year].push_back(month);
        yearPublished.push_back(year);
    }

    std::sort(yearPublished.begin(),yearPublished.end());

    for (auto i = published.begin(); i != published.end(); i++)
    {
        std::sort(i->second.begin(),i->second.end());
    }

    for (int i = 0; i < m; i++)
    {
        int year, month;
        std::cin >> year >> month;

        auto yearIt = published.find(year);

        // Case 1: Before the earliest publication
        if ((year < published.begin()->first) || 
            (year == published.begin()->first && month < published.begin()->second[0]))
        {
            std::cout << "-1 -1 ";
            continue;
        }

        // Case 2: Year exists
        if (yearIt != published.end()) {
            auto &months = yearIt->second;
            auto monthIt = std::find(months.begin(), months.end(), month);

            // Exact match
            if (monthIt != months.end()) {
                std::cout << "0 0 ";
                continue;
            }

            // Month is before all months in this year
            if (months[0] > month) {
                if (yearIt == published.begin()) {
                    std::cout << "-1 -1 ";
                } else {
                    auto prevYearIt = std::prev(yearIt);
                    std::cout << prevYearIt->first << " " << prevYearIt->second.back() << " ";
                }
                continue;
            }

            // Find the largest month less than the given month in this year
            auto lb = std::lower_bound(months.begin(), months.end(), month);
            if (lb == months.begin()) {
                // Should not happen due to previous checks
                std::cout << "-1 -1 ";
            } else {
                std::cout << year << " " << *(--lb) << " ";
            }
            continue;
        }

        // Case 3: Year does not exist, find previous year
        auto upper = published.upper_bound(year);
        if (upper == published.begin()) {
            std::cout << "-1 -1 ";
        } else {
            auto prevYearIt = std::prev(upper);
            std::cout << prevYearIt->first << " " << prevYearIt->second.back() << " ";
        }
    }
}