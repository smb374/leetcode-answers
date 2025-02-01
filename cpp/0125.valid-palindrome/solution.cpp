// Created by Po-Yeh Chen at 2025/01/24 10:42
// leetgo: 1.4.13
// https://leetcode.com/problems/valid-palindrome/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isPalindrome(string s) {
        size_t sz = s.length();
        if (sz <= 1)
            return true;

        int lo = 0, hi = sz - 1;
        while (lo < hi) {
            while (lo < hi && !isalnum(s[lo])) {
                lo++;
            }
            while (lo < hi && !isalnum(s[hi])) {
                hi--;
            }

            if (tolower(s[lo]) != tolower(s[hi]))
                return false;
            lo++;
            hi--;
        }

        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->isPalindrome(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
