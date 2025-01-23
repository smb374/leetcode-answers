// Created by Po-Yeh Chen at 2025/01/20 10:29
// leetgo: 1.4.13
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 0, res = numeric_limits<int>::max(), sum = 0, n = nums.size();

        for (int hi = 0; hi < n; hi++) {
            sum += nums[hi];
            while (sum >= target) {
                res = min(res, hi - lo + 1);
                sum -= nums[lo];
                lo++;
            }
        }

        return res == numeric_limits<int>::max() ? 0 : res;
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
