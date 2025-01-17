// Created by Po-Yeh Chen at 2025/01/17 09:05
// leetgo: 1.4.13
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size(), profit = 0,
            max_price = numeric_limits<int>::min(),
            min_price = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            if (prices[i] < min_price) {
                min_price = max_price = prices[i];
            } else {
                max_price = max(max_price, prices[i]);
            }

            profit = max(profit, max_price - min_price);
        }

        return profit;
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
