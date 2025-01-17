// Created by Po-Yeh Chen at 2025/01/17 09:42
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(), sum = 0,
            mlen = numeric_limits<int>::max();

        for (int j = 0; j < n; j++) {
            sum += nums[j];

            while (sum >= target && i <= j) {
                mlen = min(mlen, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        return mlen == numeric_limits<int>::max() ? 0 : mlen;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int target;
    LeetCodeIO::scan(cin, target);
    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    auto res = obj->minSubArrayLen(target, nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
