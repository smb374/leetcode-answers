// Created by Po-Yeh Chen at 2025/01/17 10:58
// leetgo: 1.4.13
// https://leetcode.com/problems/insert-interval/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval,
                              [](const vector<int>& a, const vector<int>& b) {
                                  return a[0] < b[0];
                              });
        intervals.insert(it, newInterval);
        res.reserve(intervals.size());

        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.emplace_back(intervals[i]);
            } else {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> intervals;
    LeetCodeIO::scan(cin, intervals);
    vector<int> newInterval;
    LeetCodeIO::scan(cin, newInterval);

    Solution* obj = new Solution();
    auto res = obj->insert(intervals, newInterval);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
