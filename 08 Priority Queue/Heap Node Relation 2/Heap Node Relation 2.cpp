#include <iostream>
#include <vector>

int relation(long long S, long long a, long long b)
{
    int A_depth = 0, B_depth = 0;
    long long A = a, B = b;

    while (A > 0)
    {
        A = (A - 1) / S;
        ++A_depth;
    }

    while (B > 0)
    {
        B = (B - 1) / S;
        ++B_depth;
    }

    A = a;
    B = b;

    if (A_depth - B_depth == 1 || B_depth - A_depth == 1)
    {
        if ((A - 1) / S == B || (B - 1) / S == A)
        {
            return 1;
        }
    }
    else
    {
        if (A > B)
        {
            while (A > B)
            {
                A = (A - 1) / S;
            }

            if (A == B)
            {
                return 2;
            }
        }

        if (B > A)
        {
            while (B > A)
            {
                B = (B - 1) / S;
            }

            if (B == A)
            {
                return 2;
            }
        }
    }

    if (A_depth != B_depth)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    long long S, a, b;
    std::cin >> n;
    while (n--)
    {
        std::cin >> S >> a >> b;
        std::cout << relation(S, a, b) << " ";
    }
    std::cout << std::endl;
}