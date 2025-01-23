// Created by Po-Yeh Chen at 2025/01/21 22:25
// leetgo: 1.4.13
// https://leetcode.com/problems/search-a-2d-matrix/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        int m = matrix.size(), n = matrix[0].size();
        int row = m - 1, col = 0;

        while (row >= 0 && col < n) {
            int elem = matrix[row][col];
            if (elem == target) {
                return true;
            } else if (elem < target) {
                col++;
            } else if (elem > target) {
                row--;
            }
        }

        return false;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> matrix;
    LeetCodeIO::scan(cin, matrix);
    int target;
    LeetCodeIO::scan(cin, target);

    Solution* obj = new Solution();
    auto res = obj->searchMatrix(matrix, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
