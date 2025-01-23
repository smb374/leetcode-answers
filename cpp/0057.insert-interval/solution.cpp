// Created by Po-Yeh Chen at 2025/01/21 08:33
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
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        res.reserve(n + 1);

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
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
