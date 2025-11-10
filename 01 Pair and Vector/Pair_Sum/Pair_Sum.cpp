#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> DATA;
    DATA.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        std::cin >> DATA[i];
    }

    sort(DATA.begin(),DATA.end());

    while (M--)
    {
        int SUM;
        std::cin >> SUM;        
        int i = 0, j = N - 1;
        bool isFound = false;

        while (i < j)
        {
            if ((DATA[i] + DATA[j]) > SUM) j--;
            else if ((DATA[i] + DATA[j]) < SUM) i++;
            else {isFound = true; break;}
        }

        if (isFound) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}