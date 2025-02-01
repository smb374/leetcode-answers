// Created by Po-Yeh Chen at 2025/01/24 09:19
// leetgo: 1.4.13
// https://leetcode.com/problems/valid-sudoku/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), columns(9), cells(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                int cx = i / 3;
                int cy = j / 3;
                int cidx = cx * 3 + cy;
                if (!rows[i].insert(c).second)
                    return false;
                if (!columns[j].insert(c).second)
                    return false;
                if (!cells[cidx].insert(c).second)
                    return false;
            }
        }

        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> board;
    LeetCodeIO::scan(cin, board);

    Solution* obj = new Solution();
    auto res = obj->isValidSudoku(board);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
