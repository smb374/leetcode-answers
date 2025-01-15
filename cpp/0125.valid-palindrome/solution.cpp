// Created by Po-Yeh Chen at 2025/01/15 12:13
// leetgo: 1.4.13
// https://leetcode.com/problems/valid-palindrome/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
            } else {
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

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->isPalindrome(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
