#include <iostream>
#include <string>
#include <map>

int main()
{
    int N,maxCount;
    maxCount = 0;
    std::string maxWord;
    std::map<std::string,int> word_count;
    std::cin >> N;

    while(N--)
    {
        std::string word;
        std::cin >> word;
        if (word_count.find(word) != word_count.end())
        {
            word_count[word]++;
        } else
        {
            word_count[word] = 1;
        }

        if (word_count[word] > maxCount)
        {
            maxCount = word_count[word];
            maxWord = (*word_count.find(word)).first;
        } else if ((maxCount == word_count[word]) && (word > maxWord))
        {
            maxWord = word;
        }
    }
    std::cout << maxWord << ' ' << maxCount;
}