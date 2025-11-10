#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>

int main()
{
    int N, M, A;
    std::cin >> N >> M >> A;
    std::vector<std::map<int, int>> user_bids(M + 1); // user_bids[user][item] = bid_value
    std::vector<std::map<int, int>> item_bids(N + 1); // user_bids[item][user] = bid_value
    std::vector<int> item_counts(N + 1);         // จำนวนของแต่ละ item

    // ประมวลผล actions
for each action
    {
        if (action == 'B')
        {
            user_bids[user][item] = bid_value;
            item_bids[item][user] = bid_value;
        }
        else
        { // 'W'
            user_bids[user].erase(item);
            item_bids[item].erase(user);
        }
    }

// หา winners สำหรับแต่ละ item
for (int item = 1; item <= N; item++)
{
    vector<pair<int, int>> bidders; // (bid_value, user_id)
    // เก็บ bidders ทั้งหมดสำหรับ item นี้
    // เรียงตาม bid_value (descending) แล้วตาม user_id (descending)
    // เลือก top K bidders
}
}