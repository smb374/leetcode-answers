// Created by Po-Yeh Chen at 2025/01/29 09:29
// leetgo: 1.4.13
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findMin(vector<int>& nums) {
        size_t sz = nums.size();
        if (sz == 0) {
            return -1;
        } else if (sz == 1) {
            return nums[0];
        } else if (nums[0] < nums[sz - 1]) {
            return nums[0];
        } else if (nums[sz - 1] < nums[sz - 2]) {
            return nums[sz - 1];
        }
        int lo = 1, hi = sz - 1;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int ml = mid - 1, mr = mid + 1;

            if (nums[ml] > nums[mid] && nums[mid] < nums[mr]) {
                return nums[mid];
            } else if (nums[mid] > nums[0]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[sz - 1]) {
                hi = mid;
            }
        }
        return -1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    auto res = obj->findMin(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
