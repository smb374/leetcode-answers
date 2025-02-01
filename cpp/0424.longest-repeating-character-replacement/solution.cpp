// Created by Po-Yeh Chen at 2025/01/26 08:29
// leetgo: 1.4.13
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int characterReplacement(string s, int k) {
        if (s.empty())
            return 0;

        size_t sz = s.size();
        int lo = 0, hi = 0, res = 0;
        int window[128] = {0}, max_freq = 0;

        while (hi < sz) {
            char c = s[hi++];
            window[c]++;
            max_freq = max(max_freq, window[c]);

            while ((hi - lo) - max_freq > k) {
                char d = s[lo++];
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->characterReplacement(s, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
