#include <iostream>
#include <string>
#include <set>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;
    std::map<std::string, std::set<std::string>> availableTicket;

    for (int i = 0; i < N; i++)
    {
        std::string flightCode, availableSeat;
        std::cin >> flightCode >> availableSeat;
        availableTicket[flightCode].insert(availableSeat);
    }

    for (int i = 0; i < M; i++)
    {
        std::map<std::string, std::set<std::string>> needed;
        bool can = true;
        int K_j;
        std::cin >> K_j;

        for (int j = 0; j < K_j; j++)
        {
            std::string neededFlight, neededSeat;
            std::cin >> neededFlight >> neededSeat;
            auto it = availableTicket.find(neededFlight);
            if (can)
            {
                if (it == availableTicket.end())
                {
                    can = false;
                } else if (availableTicket[neededFlight].find(neededSeat) == availableTicket[neededFlight].end()) {
                    can = false;
                } else {
                    needed[neededFlight].insert(neededSeat);
                }
            }
        }

        if (can)
        {
            for (auto x : needed)
            {
                for (auto j = x.second.begin(); j != x.second.end(); j++)
                {
                    availableTicket[x.first].erase(*j);
                }
            }
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}