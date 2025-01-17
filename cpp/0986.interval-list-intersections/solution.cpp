// Created by Po-Yeh Chen at 2025/01/17 11:11
// leetgo: 1.4.13
// https://leetcode.com/problems/interval-list-intersections/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int i = 0, j = 0, n = firstList.size(), m = secondList.size(),
            count = 0;
        vector<vector<int>> res;

        while (i < n && j < m) {
            auto i1 = firstList[i];
            auto i2 = secondList[j];
            int start = max(i1[0], i2[0]);
            int end = min(i1[1], i2[1]);
            if (start <= end) {
                res.push_back({start, end});
            }
            if (i1[1] < i2[1]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> firstList;
    LeetCodeIO::scan(cin, firstList);
    vector<vector<int>> secondList;
    LeetCodeIO::scan(cin, secondList);

    Solution* obj = new Solution();
    auto res = obj->intervalIntersection(firstList, secondList);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
