#include "stack.h"
#include "queue.h"

#include <algorithm>

namespace CP
{
    template <typename T>
    void stack<T>::appendStack(stack<T> s)
    {
        CP::stack<T> temp_1(s);
        CP::stack<T> temp_2;
        
        while (!(this->empty()))
        {
            temp_2.push(this->top());
            this->pop();
        }

        while (!(temp_2.empty()))
        {
            temp_1.push(temp_2.top());
            temp_2.pop();
        }

        *this = temp_1;
    }

    template <typename T>
    void stack<T>::appendQueue(queue<T> q)
    {
        CP::stack<T> temp_1;
        CP::stack<T> temp_2;

        while (!(q.empty()))
        {
            temp_1.push(q.front());
            q.pop();
        }

        while (!(temp_1.empty()))
        {
            temp_2.push(temp_1.top());
            temp_1.pop();
        }

        while (!(this->empty()))
        {
            temp_1.push(this->top());
            this->pop();
        }

        while (!(temp_1.empty()))
        {
            temp_2.push(temp_1.top());
            temp_1.pop();
        }

        *this = temp_2;
    }

    template <typename T>
    void queue<T>::appendStack(stack<T> s)
    {
        while (!(s.empty()))
        {
            this->push(s.top());
            s.pop();
        }
    }

    template <typename T>
    void queue<T>::appendQueue(queue<T> q)
    {
        while (!(q.empty()))
        {
            this->push(q.front());
            q.pop();
        }
    }
}
