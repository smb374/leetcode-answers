// Created by Po-Yeh Chen at 2025/01/21 14:56
// leetgo: 1.4.13
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    int lower_bound(const vector<int>& nums, const int& target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) {
                hi = mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid;
            }
        }

        if (lo < 0 || lo >= nums.size()) {
            return -1;
        }

        return nums[lo] == target ? lo : -1;
    }

    int upper_bound(const vector<int>& nums, const int& target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) {
                lo = mid + 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid;
            }
        }

        if (lo - 1 < 0 || lo - 1 >= nums.size()) {
            return -1;
        }

        return nums[lo - 1] == target ? lo - 1 : -1;
    }

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        int lo = lower_bound(nums, target);
        int hi = upper_bound(nums, target);
        return {lo, hi};
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
    auto res = obj->searchRange(nums, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
