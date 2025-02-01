// Created by Po-Yeh Chen at 2025/01/27 08:45
// leetgo: 1.4.13
// https://leetcode.com/problems/generate-parentheses/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    string path;
    vector<string> res;

    void backtrack(int opened, int closed, const int& n) {
        if (closed == n) {
            res.emplace_back(path);
        }

        if (opened < n) {
            path.push_back('(');
            backtrack(opened + 1, closed, n);
            path.pop_back();
        }
        if (closed < opened) {
            path.push_back(')');
            backtrack(opened, closed + 1, n);
            path.pop_back();
        }
    }

  public:
    vector<string> generateParenthesis(int n) {
        path.reserve(n * 2);
        backtrack(0, 0, n);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution* obj = new Solution();
    auto res = obj->generateParenthesis(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
