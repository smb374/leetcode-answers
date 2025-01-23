// Created by Po-Yeh Chen at 2025/01/22 14:19
// leetgo: 1.4.13
// https://leetcode.com/problems/palindrome-partitioning/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<bool>> memo;

    void backtrack(int i, const string_view& sview) {
        if (i >= sview.length()) {
            res.emplace_back(path);
            return;
        }

        for (int j = i; j < sview.length(); j++) {
            if (sview[i] == sview[j] && (j - i <= 2 || memo[i + 1][j - 1])) {
                memo[i][j] = true;
                path.emplace_back(sview.substr(i, j - i + 1));
                backtrack(j + 1, sview);
                path.pop_back();
            }
        }
    }

  public:
    vector<vector<string>> partition(string s) {
        string_view sv(s);
        path.reserve(s.length());
        memo = vector(s.size(), vector(s.size(), false));
        backtrack(0, sv);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->partition(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
