// Created by Po-Yeh Chen at 2025/01/23 11:51
// leetgo: 1.4.13
// https://leetcode.com/problems/word-search/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    const int dr[4] = {1, 0, -1, 0};
    const int dc[4] = {0, -1, 0, 1};
    bool backtrack(int r, int c, int idx, vector<vector<char>>& board,
                   const string& word) {
        int m = board.size(), n = board[0].size();
        if (idx == word.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                board[nr][nc] == word[idx]) {
                char saved = board[nr][nc];
                board[nr][nc] = '#';
                if (backtrack(nr, nc, idx + 1, board, word)) {
                    return true;
                }
                board[nr][nc] = saved;
            }
        }
        return false;
    }

  public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (!m)
            return false;
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (c == word[0]) {
                    board[i][j] = '#';
                    if (backtrack(i, j, 1, board, word)) {
                        return true;
                    }
                    board[i][j] = c;
                }
            }
        }

        return false;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> board;
    LeetCodeIO::scan(cin, board);
    string word;
    LeetCodeIO::scan(cin, word);

    Solution* obj = new Solution();
    auto res = obj->exist(board, word);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
