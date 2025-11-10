#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    int M, N;
    std::cin >> M >> N;
    std::set<int> a;
    std::set<int> b;
    std::set<int> answer;

    while(M--)
    {
        int temp1;
        std::cin >> temp1;
        if (a.find(temp1) == a.end())
        {
            a.insert(temp1);
        }
    }

    while(N--)
    {
        int temp2;
        std::cin >> temp2;
        if (b.find(temp2) == b.end())
        {
            b.insert(temp2);
        }
    }

    std::set_intersection
    (
        a.begin(),a.end(),
        b.begin(),b.end(),
        std::inserter(answer,answer.begin())
    );

    for(int value : answer)
    {
        std::cout << value << " ";
    }
    return 0;
}