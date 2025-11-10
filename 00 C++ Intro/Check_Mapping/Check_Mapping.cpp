#include <iostream>
#include <set>

std::set <int> Test;
bool Output = true;

int main() {
    int number;
    std::cin >> number;
    
    for (int i = 1; i <= number; i++) {
        Test.insert(i);
    }

    for (int i = 1; i <= number; i++) {
        int Temp;
        std::cin >> Temp;
        if ((Test.count(Temp) == 0) || (Temp < 1) || (Temp > number)) {
            Output = false;
            break;
        } else {
            Test.erase(Temp);
        }
    }

    if (Output) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}