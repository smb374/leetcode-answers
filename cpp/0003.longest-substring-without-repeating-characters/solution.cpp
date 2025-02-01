// Created by Po-Yeh Chen at 2025/01/26 08:14
// leetgo: 1.4.13
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        size_t sz = s.size();
        int lo = 0, hi = 0, mlen = 1;
        int window[128] = {0};

        while (hi < sz) {
            char c = s[hi];
            window[c]++;
            hi++;

            while (window[c] > 1) {
                char d = s[lo];
                window[d]--;
                lo++;
            }

            mlen = max(mlen, hi - lo);
        }

        return mlen;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->lengthOfLongestSubstring(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
