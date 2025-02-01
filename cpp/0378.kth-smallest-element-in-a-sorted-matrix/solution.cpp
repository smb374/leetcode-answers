// Created by Po-Yeh Chen at 2025/01/23 09:09
// leetgo: 1.4.13
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    using element = pair<int, pair<int, int>>;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<element, vector<element>, greater<>> min_heap;
        for (int i = 0; i < n; i++) {
            min_heap.push({matrix[i][0], {i, 0}});
        }

        while (--k && !min_heap.empty()) {
            element top = min_heap.top();
            min_heap.pop();
            auto [r, c] = top.second;

            if (c + 1 < n) {
                min_heap.push({matrix[r][c + 1], {r, c + 1}});
            }
        }

        return min_heap.top().first;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> matrix;
    LeetCodeIO::scan(cin, matrix);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->kthSmallest(matrix, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
