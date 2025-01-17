// Created by Po-Yeh Chen at 2025/01/17 09:25
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-window-substring/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// @lc code=begin

class Solution {
  public:
    string minWindow(string s, string t) {
        // Edge case
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        int target[128] = {0}, window[128] = {0}, required = 0, formed = 0;
        int lo = 0, hi = 0, n = s.length(), mlen = numeric_limits<int>::max(),
            base = 0;

        for (const char c : t) {
            if (!target[c])
                required++;
            target[c]++;
        }

        while (hi < n) {
            char c = s[hi];
            window[c]++;
            if (target[c] && target[c] == window[c]) {
                formed++;
            }

            while (lo <= hi && formed == required) {
                if (hi - lo + 1 < mlen) {
                    mlen = hi - lo + 1;
                    base = lo;
                }

                c = s[lo];
                window[c]--;
                if (target[c] && window[c] < target[c]) {
                    formed--;
                }
                lo++;
            }
            hi++;
        }

        return mlen == numeric_limits<int>::max() ? "" : s.substr(base, mlen);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    string t;
    LeetCodeIO::scan(cin, t);

    Solution* obj = new Solution();
    auto res = obj->minWindow(s, t);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
