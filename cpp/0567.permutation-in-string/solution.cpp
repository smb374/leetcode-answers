// Created by Po-Yeh Chen at 2025/01/21 13:49
// leetgo: 1.4.13
// https://leetcode.com/problems/permutation-in-string/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool checkInclusion(string t, string s) {
        int m = s.size(), n = t.size();
        int required = 0, formed = 0, lo = 0, hi = 0;
        int target[128] = {0}, window[128] = {0};

        for (const char c : t) {
            if (!target[c]) {
                required++;
            }
            target[c]++;
        }

        while (hi < m) {
            char c = s[hi++];
            // unlike 76, the match need to have the same characters in
            // t so we increase window only if the character is in t.
            if (target[c]) {
                window[c]++;
                if (window[c] == target[c]) {
                    formed++;
                }
            }
            while (hi - lo >= n) {
                if (formed == required) {
                    return true;
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
        return false;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s1;
    LeetCodeIO::scan(cin, s1);
    string s2;
    LeetCodeIO::scan(cin, s2);

    Solution* obj = new Solution();
    auto res = obj->checkInclusion(s1, s2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
