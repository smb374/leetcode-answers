// Created by Po-Yeh Chen at 2025/01/25 09:22
// leetgo: 1.4.13
// https://leetcode.com/problems/trapping-rain-water/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <stack>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int trap(vector<int>& height) {
        size_t sz = height.size();
        if (sz == 0)
            return 0;
        int res = 0;
        vector<int> hl_max(sz);

        hl_max[0] = height[0];
        int hh_max = height[sz - 1];

        for (int i = 1; i < sz; i++) {
            hl_max[i] = max(hl_max[i - 1], height[i]);
        }

        for (int i = sz - 2; i > 0; i--) {
            res += max(min(hl_max[i - 1], hh_max) - height[i], 0);
            hh_max = max(hh_max, height[i]);
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> height;
    LeetCodeIO::scan(cin, height);

    Solution* obj = new Solution();
    auto res = obj->trap(height);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
