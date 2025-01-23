// Created by Po-Yeh Chen at 2025/01/21 14:04
// leetgo: 1.4.13
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        int target[128] = {0}, window[128] = {0};
        int required = 0, formed = 0, lo = 0, hi = 0;
        vector<int> res;

        for (const char c : p) {
            if (!target[c])
                required++;
            target[c]++;
        }

        while (hi < m) {
            char c = s[hi++];
            if (target[c]) {
                window[c]++;
                if (target[c] == window[c]) {
                    formed++;
                }
            }

            while (hi - lo >= n) {
                if (formed == required) {
                    res.push_back(lo);
                }

                c = s[lo++];
                if (target[c]) {
                    if (target[c] == window[c])
                        formed--;
                    window[c]--;
                }
            }
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
    string p;
    LeetCodeIO::scan(cin, p);

    Solution* obj = new Solution();
    auto res = obj->findAnagrams(s, p);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
