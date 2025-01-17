// Created by Po-Yeh Chen at 2025/01/17 10:26
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <string>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minFlips(string s) {
        int n = s.length(), n2 = n << 1, diff = 0,
            res = numeric_limits<int>::max();
        string pat(n2, '1');
        for (int i = 0; i < n; i++) {
            pat[i << 1] = '0';
        }

        for (int i = 0; i < n; i++) {
            diff += (pat[i] != s[i]);
        }
        for (int i = n; i < n2; i++) {
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
