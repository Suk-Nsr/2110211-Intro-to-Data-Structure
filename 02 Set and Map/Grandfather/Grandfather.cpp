#include <iostream>
#include <map>

int N, M;
std::map <long long, long long> sonFather;

bool isGrandfatherExist(long long id1, long long id2)
{
    if (id1 == id2) {return false;}
    
    bool a = (sonFather.find(id1) != sonFather.end());
    bool b = (sonFather.find(id2) != sonFather.end());

    if (a && b)
    {
        bool c = (sonFather.find(sonFather[id1]) != sonFather.end());
        bool d = (sonFather.find(sonFather[id2]) != sonFather.end());
        if (c && d)
        {
            return true;
        } else
        {
            return false;
        }
    }
    return false;
}

bool isSameGrandfather(long long id1, long long id2)
{
    if (isGrandfatherExist(id1, id2))
    {
        return (sonFather[sonFather[id1]] == sonFather[sonFather[id2]]);
    }
    return false;
}

int main ()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    std::cin >> N >> M;
    
    while(N--)
    {
        long long F, S;
        std::cin >> F >> S;
        sonFather[S] = F;
    }

    while(M--)
    {
        long long id1, id2;
        std::cin >> id1 >> id2;
        if (isSameGrandfather(id1, id2))
        {
            std::cout << "YES\n";
        } else
        {
            std::cout << "NO\n";
        }
    }
}