// Created by Po-Yeh Chen at 2025/01/17 10:20
// leetgo: 1.4.13
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int characterReplacement(string s, int k) {
        int freq[128] = {0}, lo = 0, n = s.size(), max_freq = 0, max_len = 0;

        for (int hi = 0; hi < n; hi++) {
            freq[s[hi]]++;
            max_freq = max(max_freq, freq[s[hi]]);

            if ((hi - lo + 1) - max_freq > k) {
                freq[s[lo]]--;
                lo++;
            }

            max_len = max(max_len, hi - lo + 1);
        }

        return max_len;
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
