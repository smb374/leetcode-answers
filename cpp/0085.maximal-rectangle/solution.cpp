// Created by Po-Yeh Chen at 2025/01/29 16:11
// leetgo: 1.4.13
// https://leetcode.com/problems/maximal-rectangle/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<pair<int, int>> st;
    int largest_rect_histogram(vector<int>& heights) {
        int sz = heights.size();
        int max_area = 0;

        for (int i = 0; i < sz; i++) {
            int start = i;
            while (!st.empty() && st.back().second > heights[i]) {
                auto [idx, height] = st.back();
                st.pop_back();
                max_area = max(max_area, height * (i - idx));
                start = idx;
            }
            st.emplace_back(start, heights[i]);
        }
        while (!st.empty()) {
            auto [idx, height] = st.back();
            st.pop_back();
            max_area = max(max_area, height * (sz - idx));
        }
        return max_area;
    }

  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        if (matrix[0].empty())
            return 0;

        int m = matrix.size(), n = matrix[0].size();
        int max_area = 0;
        vector<int> h(n, 0);

        st.reserve(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                h[j] = (matrix[i][j] == '1' ? h[j] + 1 : 0);
            }
            max_area = max(max_area, largest_rect_histogram(h));
        }

        return max_area;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> matrix;
    LeetCodeIO::scan(cin, matrix);

    Solution* obj = new Solution();
    auto res = obj->maximalRectangle(matrix);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
