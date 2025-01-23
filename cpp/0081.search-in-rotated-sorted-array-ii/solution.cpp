// Created by Po-Yeh Chen at 2025/01/22 10:13
// leetgo: 1.4.13
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool search(vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[lo]) {
                lo++;
                continue;
            }

            if (nums[mid] > nums[lo]) {
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (target <= nums[hi - 1] && target > nums[mid]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
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
