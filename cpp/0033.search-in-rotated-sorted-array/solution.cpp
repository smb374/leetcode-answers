// Created by Po-Yeh Chen at 2025/01/29 09:40
// leetgo: 1.4.13
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        size_t sz = nums.size();
        int lo = 0, hi = sz;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[0]) {
                if (target >= nums[0] && target <= nums[mid]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            } else if (nums[mid] <= nums[sz - 1]) {
                if (target <= nums[sz - 1] && target >= nums[mid]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
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
    int target;
    LeetCodeIO::scan(cin, target);

    Solution* obj = new Solution();
    auto res = obj->search(nums, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
