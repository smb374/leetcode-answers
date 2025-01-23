// Created by Po-Yeh Chen at 2025/01/20 10:24
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <limits>
#include <string>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minFlips(string s) {
        int n = s.length(), diff = 0, res;
        string pat(n * 2, '1');

        for (int i = 0; i < n; i++) {
            pat[i << 1] = '0';
        }

        for (int i = 0; i < n; i++) {
            diff += pat[i] != s[i];
        }
        res = min(diff, n - diff);
        for (int i = n; i < n * 2; i++) {
            diff += (pat[i] != s[i - n]) - (pat[i - n] != s[i - n]);
            res = min(res, min(diff, n - diff));
        }

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
    auto res = obj->minFlips(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
