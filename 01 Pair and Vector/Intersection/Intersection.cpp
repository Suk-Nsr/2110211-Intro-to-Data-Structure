#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::vector<int> a, b, answer;
    std::cin >> N >> M;

    while(N--)
    {
        int temp1;
        std::cin >> temp1;
        if(find(a.begin(),a.end(),temp1) == a.end())
        {
            a.push_back(temp1);
        }
    }
    sort(a.begin(),a.end());

    while(M--)
    {
        int temp2;
        std::cin >> temp2;
        if(find(b.begin(),b.end(),temp2) == b.end())
        {
            b.push_back(temp2);
        }
    }
    sort(b.begin(),b.end());

    for(int i : a)
    {
        if(find(b.begin(),b.end(),i) != b.end())
        {
            answer.push_back(i);
        }
    }

    for(int j : answer)
    {
        std::cout << j << " ";
    }
}