#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Just here for the code to do std::cin and std::cout faster
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // create 3 variables called R, R and k then request an input for each variables
    long long R, C;
    int k;
    std::cin >> R >> C >> k;

    // create a vector named "fav" with long long type of data
    // Also reserved some extra space for future .push_back() function so the vector doesn't need to extend everytime
    std::vector<long long> fav;
    fav.reserve(k);

    // Do k amount loops to store the cordinate of the favorite chocolate.
    while (k--)
    {
        // create 2 temporary variables for the cordinate of the favorited chocolate
        long long x, y;
        std::cin >> x >> y;

        // modified the x, y cordinate number into a single number
        long long fav_position = (((x - 1) * C) + y);
        fav.push_back(fav_position);
    }
    // sort everything out to corrected the favorite chocolate order in case that the testcase want to troll us
    sort(fav.begin(),fav.end());

    // recieve an input to know the amount of the questions
    long long Q;
    std::cin >> Q;

    // calculate the total position possible of the box
    long long total_position = R * C;

    while (Q--)
    {
        // create 2 temporary variable for the cordinate of the starting point
        long long p, q;
        std::cin >> p >> q;

        // modified the p, q cordinate number into a single number
        long long start_position = (((p - 1) * C) + q);

        // create an iterator variable that tell us which favorite chocolate will hit first
        std::vector<long long>::iterator it = std::lower_bound(fav.begin(), fav.end(), start_position);

        long long answer;
        if (it != fav.end())
        {
            answer = *it - start_position;                          // find the delta of both value to tell us the day difference
        } else
        {
            answer = (total_position - start_position) + fav[0];    // already look until the end of the data? Find the days left until the end of the box + days until reach a favorite chocolate
        }
        std::cout << answer << "\n";
    }
    return 0;
}