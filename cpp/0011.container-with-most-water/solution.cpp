// Created by Po-Yeh Chen at 2025/01/25 09:06
// leetgo: 1.4.13
// https://leetcode.com/problems/container-with-most-water/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxArea(vector<int>& height) {
        size_t sz = height.size();
        int lo = 0, hi = sz - 1, max_area = 0;

        while (lo < hi) {
            int hl = height[lo], hh = height[hi];
            int width = hi - lo;

            if (hl < hh) {
                max_area = max(max_area, width * hl);
                lo++;
            } else {
                max_area = max(max_area, width * hh);
                hi--;
            }
        }

        return max_area;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> height;
    LeetCodeIO::scan(cin, height);

    Solution* obj = new Solution();
    auto res = obj->maxArea(height);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
