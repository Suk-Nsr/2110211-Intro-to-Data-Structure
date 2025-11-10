#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>

int N, M, totalCapacity = 0;
std::map<int, std::priority_queue<int>> capacityFloor;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    std::cin >> N >> M;

    for (int floor = 1; floor <= N; floor++)
    {
        int capacity;
        std::cin >> capacity;
        capacityFloor[capacity].push(floor);
        totalCapacity += capacity;
    }

    while(M--)
    {
        int customers;
        std::vector<std::pair<int, int>> output;
        std::cin >> customers;

        if (customers > totalCapacity) {std::cout << "-1";}
        else
        {
            totalCapacity -= customers;

            while (customers > 0)
            {
                auto max_it = capacityFloor.lower_bound(customers);
                int floor, booked, capacity;
                if (max_it == capacityFloor.end()) {max_it--;}
                capacity = (*max_it).first;
                booked = std::min(capacity, customers);
                floor = (*max_it).second.top();
                output.push_back(std::make_pair(floor, booked));
                capacityFloor[capacity - booked].push(floor);
                (*max_it).second.pop();
                if ((*max_it).second.empty()) {capacityFloor.erase(max_it);}
                customers -= booked;
            }
            sort(output.begin(),output.end());
            for (auto [floor, booked] : output)
            {
                std::cout << floor << " " << booked << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}