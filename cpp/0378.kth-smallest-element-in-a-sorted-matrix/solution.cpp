// Created by Po-Yeh Chen at 2025/01/20 09:16
// leetgo: 1.4.13
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    // Finding the number of divided elements by mid.
    int saddleback_lowerbound(const vector<vector<int>>& matrix, int mid) {
        int count = 0, n = matrix.size();
        int row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }

        return count;
    }

  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int count = saddleback_lowerbound(matrix, mid);

            if (count < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
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
