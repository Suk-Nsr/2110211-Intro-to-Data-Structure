#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::vector<int> Size, Answer;
    std::cin >> N >> M;

    while (N--) {
        int available_size;
        std::cin >> available_size;
        Size.push_back(available_size);
    }

    std::sort(Size.begin(),Size.end());

    while (M--) {
        int customers_needed;
        std::cin >> customers_needed;
        auto it = std::lower_bound(Size.begin(),Size.end(),customers_needed);
        if (it == Size.begin()) {
            Answer.push_back(*it);
        } else if (it == Size.end()) {
            Answer.push_back(*(it - 1));
        } else if (((*it) - customers_needed) == (customers_needed - (*(it - 1)))) {
            Answer.push_back(*it);
        } else if (((*it) - customers_needed) > (customers_needed - (*(it - 1)))) {
            Answer.push_back(*(it - 1));
        } else if (((*it) - customers_needed) < (customers_needed - (*(it - 1)))) {
            Answer.push_back(*it);
        }
    }

    for(int a : Answer) {
        std::cout << a << " ";
    }
    return 0;
}