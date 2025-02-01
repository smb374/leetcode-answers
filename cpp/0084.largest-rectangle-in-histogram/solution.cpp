// Created by Po-Yeh Chen at 2025/01/28 17:48
// leetgo: 1.4.13
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <stack>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        int maxArea = 0;
        vector<pair<int, int>> st;
        st.reserve(sz);

        for (int i = 0; i < sz; i++) {
            int start = i;
            while (!st.empty() && heights[i] < st.back().second) {
                auto [idx, h] = st.back();
                maxArea = max(maxArea, h * (i - idx));
                start = idx;
                st.pop_back();
            }
            st.emplace_back(start, heights[i]);
        }

        while (!st.empty()) {
            auto [idx, h] = st.back();
            maxArea = max(maxArea, h * (sz - idx));
            st.pop_back();
        }

        return maxArea;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> heights;
    LeetCodeIO::scan(cin, heights);

    Solution* obj = new Solution();
    auto res = obj->largestRectangleArea(heights);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
