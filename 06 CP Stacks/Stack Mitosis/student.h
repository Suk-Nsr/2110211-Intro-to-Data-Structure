#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <vector>

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    std::vector<T> noYaekRak;
    std::vector<T> yaekRak;
    int i = 0;

    while (i < a)
    {
        noYaekRak.push_back(this->top());
        this->pop();
        i++;
    }

    while (i <= b)
    {
        yaekRak.push_back(this->top());
        this->pop();
        i++;
    }

    for (int j = yaekRak.size(); j > 0; j--)
    {
        this->push(yaekRak[j - 1]);
        this->push(yaekRak[j - 1]);
    }

    for (int j = noYaekRak.size(); j > 0; j--)
    {
        this->push(noYaekRak[j - 1]);
    }
}

#endif