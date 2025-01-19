// Created by Po-Yeh Chen at 2025/01/18 09:12
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-window-subsequence/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <csignal>
#include <cstddef>
#include <limits>
using namespace std;

// @lc code=begin

class Solution {
  public:
    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int i = 0, satisfied = 0, base = 0, mlen = numeric_limits<int>::max();

        while (i < n) {
            if (s1[i] == s2[satisfied]) {
                satisfied++;
            }
            i++;

            if (satisfied == m) {
                int lo = i, hi = i, j = satisfied;
                while (j) {
                    if (s1[lo - 1] == s2[j - 1]) {
                        j--;
                    }
                    lo--;
                }

                if (hi - lo < mlen) {
                    mlen = hi - lo;
                    base = lo;
                }

                i = lo + 1;
                satisfied = 0;
            }
        }

        return mlen == numeric_limits<int>::max() ? "" : s1.substr(base, mlen);
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
    auto res = obj->minWindow(s1, s2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
