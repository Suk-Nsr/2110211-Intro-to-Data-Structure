#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    bool defeated = false;
    int n, m, stage = 1;
    std::cin >> n >> m;
    std::multiset<int> arjarnToeCard;
    
    for (int i = 0; i < n; i++)
    {
        int cardPower;
        std::cin >> cardPower;
        arjarnToeCard.insert(cardPower);
    }

    for (int i = 0; i < m; i++)
    {
        int cardNumber;
        std::cin >> cardNumber;
        for (int j = 0; j < cardNumber; j++)
        {
            int enemyCardPower;
            std::cin >> enemyCardPower;
            if (defeated) 
            {
                break;
            }
            auto it = arjarnToeCard.upper_bound(enemyCardPower);
            if (it == arjarnToeCard.end())
            {
                defeated = true;
                break;
            } else {
                arjarnToeCard.erase(it);
            }
        }
        if (!defeated)
        {
            stage++;
        }
    }
    std::cout << stage;
}