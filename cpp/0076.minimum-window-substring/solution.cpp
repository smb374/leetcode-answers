// Created by Po-Yeh Chen at 2025/01/26 08:46
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-window-substring/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size())
            return "";
        size_t m = s.size(), n = t.size();
        int lo = 0, hi = 0, required = 0, formed = 0;
        int base = 0, mlen = INT_MAX;
        int window[128] = {0}, target[128] = {0};

        for (const char c : t) {
            if (!target[c])
                required++;
            target[c]++;
        }

        while (hi < m) {
            char c = s[hi++];
            window[c]++;
            if (window[c] == target[c]) {
                formed++;
            }

            while (formed == required) {
                if (hi - lo < mlen) {
                    mlen = hi - lo;
                    base = lo;
                }

                char d = s[lo++];
                window[d]--;
                if (window[d] < target[d]) {
                    formed--;
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
