#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    
    std::vector<int> perfectPair;
    int N, follower = 0;
    long long answer = 0;
    std::cin >> N;
    perfectPair.resize(N);

    for (int i = 0; i < N; i++) {
        std::cin >> perfectPair[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> follower;
        perfectPair[i] -= follower;
    }

    sort(perfectPair.begin(),perfectPair.end());

    for (int i = 0; i < (N - 1); i++) {
        int j = std::upper_bound(perfectPair.begin() + i + 1, perfectPair.end(), -perfectPair[i]) - perfectPair.begin();
        answer += N - j;
    }
    std::cout << answer;
    return 0;
}