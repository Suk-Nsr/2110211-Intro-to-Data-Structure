#include <iostream>
#include <utility>
#include <list>

std::pair<bool, std::pair<std::pair<bool, bool>, std::pair<std::list<int>::iterator, std::list<int>::iterator>>> validExplodeCheck(std::list<int> &zumaDeluxe, std::list<int>::iterator pos)
{
    if (zumaDeluxe.empty() || pos == zumaDeluxe.end())
    {
        return std::make_pair(false, std::make_pair(std::make_pair(false, false), std::make_pair(zumaDeluxe.end(), zumaDeluxe.end())));
    }

    int ball$ = 0;
    bool left = false, right = false;
    std::list<int>::iterator temp_1 = pos;
    std::list<int>::iterator another_temp_1 = temp_1;
    another_temp_1--;

    if (*(another_temp_1) == *pos)
    {
        left = true;
    }

    while ((temp_1 != zumaDeluxe.begin()) && (*(temp_1) == *pos))
    {
        ball$++;
        --temp_1;
    }

    std::list<int>::iterator temp_2 = pos;
    std::list<int>::iterator another_temp_2 = temp_1;
    another_temp_2++;

    if (*(another_temp_2) == *pos)
    {
        right = true;
    }

    while ((temp_2 != zumaDeluxe.end()) && (*(temp_2) == *pos))
    {
        ball$++;
        ++temp_2;
    }

    if (temp_1 != zumaDeluxe.begin())
    {
        temp_1++;
    }

    return std::make_pair(ball$ >= 3, std::make_pair(std::make_pair(left, right), std::make_pair(temp_1, temp_2)));
}

int main()
{
    std::list<int> zumaDeluxe;
    int N, K, V;
    std::cin >> N >> K >> V;

    for (int i = 0; i < N; i++)
    {
        int initialize;
        std::cin >> initialize;
        zumaDeluxe.push_back(initialize);
    }

    std::list<int>::iterator it_1 = zumaDeluxe.begin();

    for (int i = 0; i < K; i++)
    {
        it_1++;
    }

    std::list<int>::iterator it_2 = zumaDeluxe.insert(it_1, V);
    std::list<int>::iterator it_2_left = it_2, it_2_right = it_2;
    int firstCount = 1;
    std::pair<bool, std::pair<std::pair<bool, bool>, std::pair<std::list<int>::iterator, std::list<int>::iterator>>> result;

    while (it_2_left != zumaDeluxe.begin() && (*(it_2_left) == *it_2))
    {
        firstCount++;
        it_2_left--;
    }

    while (it_2_right != zumaDeluxe.begin() && (*(it_2_right) == *it_2))
    {
        firstCount++;
        it_2_right++;
    }

    firstCount--;
    firstCount--;
    it_2_left++;
    result = std::make_pair(firstCount >= 3, std::make_pair(std::make_pair(true, true), std::make_pair(it_2_left, it_2_right)));

    while (result.first)
    {
        std::list<int>::iterator it_3 = zumaDeluxe.end();

        if (result.second.first.first && result.second.first.second)
        {
            it_3 = zumaDeluxe.erase(result.second.second.first, result.second.second.second);
        }
        else
        {
            break;
        }

        if (zumaDeluxe.empty())
        {
            result = std::make_pair(false, std::make_pair(std::make_pair(false, false), std::make_pair(zumaDeluxe.end(), zumaDeluxe.end())));
        }
        else
        {
            std::list<int>::iterator check_pos;
            if (it_3 == zumaDeluxe.end())
            {
                check_pos = std::prev(it_3);
            }
            else
            {
                check_pos = it_3;
            }
            result = validExplodeCheck(zumaDeluxe, check_pos);
        }
    }

    for (int i : zumaDeluxe)
    {
        std::cout << i << " ";
    }
}