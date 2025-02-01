// Created by Po-Yeh Chen at 2025/01/23 11:09
// leetgo: 1.4.13
// https://leetcode.com/problems/n-queens/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<string> board;
    vector<vector<string>> solutions;
    unordered_set<int> cols, diags, anti_diags;

    void backtrack(int row, const int& n) {
        if (row == n) {
            solutions.emplace_back(board);
        }

        for (int col = 0; col < n; col++) {
            int diag = row - col, anti_diag = row + col;
            if (cols.count(col) || diags.count(diag) ||
                anti_diags.count(anti_diag)) {
                continue;
            }
            cols.insert(col);
            diags.insert(diag);
            anti_diags.insert(anti_diag);
            board[row][col] = 'Q';
            backtrack(row + 1, n);
            cols.erase(col);
            diags.erase(diag);
            anti_diags.erase(anti_diag);
            board[row][col] = '.';
        }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector(n, string(n, '.'));

        backtrack(0, n);

        return solutions;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution* obj = new Solution();
    auto res = obj->solveNQueens(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
