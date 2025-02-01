// Created by Po-Yeh Chen at 2025/01/28 10:23
// leetgo: 1.4.13
// https://leetcode.com/problems/koko-eating-bananas/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int time = 0;
            for (int p : piles) {
                time += p / mid + (p % mid != 0);
            }

            if (time <= h) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> piles;
    LeetCodeIO::scan(cin, piles);
    int h;
    LeetCodeIO::scan(cin, h);

    Solution* obj = new Solution();
    auto res = obj->minEatingSpeed(piles, h);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
