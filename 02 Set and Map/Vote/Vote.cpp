#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    int N, K;
    std::map<std::string,int> voteCount;
    std::vector<int> score;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        std::string whoVote;
        std::cin >> whoVote;
        auto it = voteCount.find(whoVote);
        if (it == voteCount.end())
        {
            voteCount[whoVote] = 1;
        } else {
            voteCount[whoVote]++;
        }
    }

    for (const auto &x : voteCount)
    {
        score.push_back(x.second);
    }

    std::sort(score.begin(), score.end());

    if (score.size() < K)
    {
        std::cout << score[0];
    } else {
        std::cout << score[score.size() - K];
    }
}