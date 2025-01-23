// Created by Po-Yeh Chen at 2025/01/21 14:10
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-window-substring/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
using namespace std;

// @lc code=begin

class Solution {
  public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int target[128] = {0}, window[128] = {0};
        int required = 0, formed = 0, lo = 0, hi = 0;
        int base = 0, mlen = INT_MAX;
        for (const char c : t) {
            if (!target[c])
                required++;
            target[c]++;
        }

        while (hi < m) {
            char c = s[hi++];
            if (target[c]) {
                window[c]++;
                if (window[c] == target[c]) {
                    formed++;
                }
            }

            while (formed == required) {
                if (hi - lo < mlen) {
                    mlen = hi - lo;
                    base = lo;
                }

                char d = s[lo++];
                if (target[d]) {
                    if (window[d] == target[d]) {
                        formed--;
                    }
                    window[d]--;
                }
            }
        }
        return mlen == INT_MAX ? "" : s.substr(base, mlen);
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
