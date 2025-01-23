// Created by Po-Yeh Chen at 2025/01/21 09:38
// leetgo: 1.4.13
// https://leetcode.com/problems/interval-list-intersections/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;

        while (i < m && j < n) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (start <= end)
                res.push_back({start, end});

            if (firstList[i][1] < secondList[j][1]) {
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
