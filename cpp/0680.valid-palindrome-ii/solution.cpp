// Created by Po-Yeh Chen at 2025/01/18 09:55
// leetgo: 1.4.13
// https://leetcode.com/problems/valid-palindrome-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
    bool validPalindromeRange(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

  public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return validPalindromeRange(s, i + 1, j) ||
                       validPalindromeRange(s, i, j - 1);

            i++;
            j--;
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
    auto res = obj->validPalindrome(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
