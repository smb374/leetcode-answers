// Created by Po-Yeh Chen at 2025/01/25 10:09
// leetgo: 1.4.13
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        size_t sz = prices.size();
        int max_price = INT_MIN, min_price = INT_MAX, res = 0;

        for (int i = 0; i < sz; i++) {
            if (prices[i] < min_price) {
                max_price = min_price = prices[i];
            } else if (prices[i] > max_price) {
                max_price = prices[i];
            }

            res = max(res, max_price - min_price);
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> prices;
    LeetCodeIO::scan(cin, prices);

    Solution* obj = new Solution();
    auto res = obj->maxProfit(prices);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
