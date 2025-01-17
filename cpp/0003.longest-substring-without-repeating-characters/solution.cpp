// Created by Po-Yeh Chen at 2025/01/17 09:00
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
        if (s.empty())
            return 0;
        int seen[128] = {0}, max_len = 1, i = 0, n = s.length();

        for (int j = 0; j < n; j++) {
            i = max(i, seen[s[j]]);
            max_len = max(max_len, j - i + 1);
            seen[s[j]] = j + 1;
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

    Solution* obj = new Solution();
    auto res = obj->lengthOfLongestSubstring(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
