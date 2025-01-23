// Created by Po-Yeh Chen at 2025/01/22 11:13
// leetgo: 1.4.13
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    string path;
    unordered_map<char, string> letter_map = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    void backtrack(int idx, vector<string>& res, const string& digits) {
        if (idx == digits.size()) {
            res.emplace_back(path);
        }

        string letters = letter_map[digits[idx]];
        for (const char letter : letters) {
            path.push_back(letter);
            backtrack(idx + 1, res, digits);
            path.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        path.reserve(digits.size());
        vector<string> res;
        backtrack(0, res, digits);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string digits;
    LeetCodeIO::scan(cin, digits);

    Solution* obj = new Solution();
    auto res = obj->letterCombinations(digits);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
