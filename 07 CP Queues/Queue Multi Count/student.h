#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <unordered_map>

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const
{
    std::vector<std::pair<T, size_t>> answer;
    std::unordered_map<T, size_t> count;
    CP::queue<T> copied = *this;

    for (T value : k)
    {
        count[value] = 0;
    }

    while (!(copied.empty()))
    {
        auto it = count.find(copied.front());
        if (it != count.end())
        {
            count[copied.front()]++;
        }
        copied.pop();
    }

    for (T value : k)
    {
        answer.push_back({value, count[value]});
    }

    return answer;
}

#endif
