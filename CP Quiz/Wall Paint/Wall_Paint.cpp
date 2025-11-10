#include <iostream>
#include <utility>
#include <vector>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M, maxThick = 0;
    std::cin >> N >> M;
    std::set<std::pair<int, int>> paintInterval;
    std::vector<int> startPos(M), endPos(M);

    for (int i = 0; i < 2 * M; i++)
    {
        int x, c, d;
        std::cin >> x >> c >> d;
        if (d == 0)
        {
            startPos[c - 1] = x - 1;
        }
        if (d == 1)
        {
            endPos[c - 1] = x - 1;
        }
    }

    paintInterval.insert({startPos[0], 0});
    paintInterval.insert({endPos[0], 1});

    for (int i = 1; i < M; i++)
    {
        auto it_1 = paintInterval.lower_bound({startPos[i], 0});
        auto it_2 = paintInterval.lower_bound({endPos[i], 1});
        if (it_1 != it_2)
        {
            continue;
        }
        if (it_1->first == startPos[i])
        {
            continue;
        }
        if (it_2->first == endPos[i])
        {
            continue;
        }
        paintInterval.insert({startPos[i], 0});
        paintInterval.insert({endPos[i], 1});
    }

    int thickness = 0;

    for (auto x : paintInterval)
    {
        if (x.second == 0)
        {
            thickness++;
        }
        if (x.second == 1)
        {
            thickness--;
        }
        if (thickness > maxThick)
        {
            maxThick = thickness;
        }
    }
    std::cout << maxThick;
}