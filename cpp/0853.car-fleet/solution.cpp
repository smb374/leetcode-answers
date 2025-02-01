// Created by Po-Yeh Chen at 2025/01/28 09:20
// leetgo: 1.4.13
// https://leetcode.com/problems/car-fleet/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        size_t sz = position.size();
        vector<pair<int, int>> cars(sz);
        vector<double> st;

        for (int i = 0; i < sz; i++) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        // Sort the cars in descending order by position then speed
        // since the cars in the back can catch up.
        sort(cars.begin(), cars.end(), greater<>{});
        // For this problem, we need to maintain a
        // monotonic increase stack on arriving time.
        // Because the arriving time is capped by front cars (stack top),
        // lower arriving time cars will form a fleet with stack top,
        // only the cars that arrives later then the stack top can form another
        // fleet for cars after it.
        for (auto& c : cars) {
            auto [pos, speed] = c;
            double time = (double)(target - pos) / speed;
            if (st.empty() || time > st.back()) {
                st.push_back(time);
            }
        }

        return st.size();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int target;
    LeetCodeIO::scan(cin, target);
    vector<int> position;
    LeetCodeIO::scan(cin, position);
    vector<int> speed;
    LeetCodeIO::scan(cin, speed);

    Solution* obj = new Solution();
    auto res = obj->carFleet(target, position, speed);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
