#include <iostream>

int N, M, Time = 0;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    std::cin >> N >> M;
    int chef_time[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> chef_time[i];
    }

    while (M > 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (M == 0)
            {
                break;
            }
            if (Time == 0 || Time % chef_time[i] == 0)
            {
                std::cout << Time << "\n";
                M--;
            }
        }
        Time++;
    }
    return 0;
}