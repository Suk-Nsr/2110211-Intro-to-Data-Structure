#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> wordCount;
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::string word;
        std::cin >> word;
        
        auto it = wordCount.find(word);
        if (it == wordCount.end())
        {
            wordCount[word] = 1;
        } else {
            wordCount[word]++;
        }
    }

    for (auto x : wordCount)
    {
        if (x.second > 1)
        {
            std::cout << x.first << " " << x.second << "\n";
        }
    }
}