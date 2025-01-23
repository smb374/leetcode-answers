// Created by Po-Yeh Chen at 2025/01/22 10:03
// leetgo: 1.4.13
// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int ml = mid - 1, mr = mid + 1;
            bool hi_even = (hi - mid) % 2 == 0;
            if (nums[ml] == nums[mid]) {
                // ... ml mid ...
                if (hi_even) {
                    hi = ml - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (nums[mr] == nums[mid]) {
                // ... mid mr ...
                if (hi_even) {
                    lo = mr + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                return nums[mid];
            }
        }

        return nums[lo];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    auto res = obj->singleNonDuplicate(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
