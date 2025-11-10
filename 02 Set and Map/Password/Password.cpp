#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    std::vector<char> charList = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y'};
    int N, M, L;
    std::cin >> N >> M >> L;
    std::vector<int> charOffset;
    std::set<std::string> storedPassword;

    for (int i = 0; i < L; i++)
    {
        int offset;
        std::cin >> offset;
        offset = offset % 26;
        charOffset.push_back(offset);
    }

    for (int i = 0; i < N; i++)
    {
        std::string encryptedPassword;
        std::cin >> encryptedPassword;
        storedPassword.insert(encryptedPassword);
    }

    for (int i = 0; i < M; i++)
    {
        std::string Password, result = "";
        std::cin >> Password;

        for (int j = 0; j < L; j++)
        {
            auto it_1 = std::lower_bound(charList.begin(), charList.end(), Password[j]);
            it_1 = it_1 + charOffset[j];
            result += (*it_1);
        }
        auto it_2 = storedPassword.find(result);
        if (it_2 == storedPassword.end())
        {
            std::cout << "Unknown\n";
        } else {
            std::cout << "Match\n";
        }
    }
}