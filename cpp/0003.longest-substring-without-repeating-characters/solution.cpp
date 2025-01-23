// Created by Po-Yeh Chen at 2025/01/21 14:17
// leetgo: 1.4.13
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int window[128] = {0};
        int lo = 0, hi = 0, n = s.length(), res = 0;

        while (hi < n) {
            char c = s[hi];
            hi++;
            window[c]++;

            while (window[c] > 1) {
                char d = s[lo];
                lo++;
                window[d]--;
            }

            res = max(res, hi - lo);
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
    auto res = obj->lengthOfLongestSubstring(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
