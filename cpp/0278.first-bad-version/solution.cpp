// Created by Po-Yeh Chen at 2025/01/22 09:47
// leetgo: 1.4.13
// https://leetcode.com/problems/first-bad-version/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
        // Lower Bound
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (isBadVersion(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int bad;
    LeetCodeIO::scan(cin, bad);

    Solution* obj = new Solution();
    auto res = obj->firstBadVersion(n, bad);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
