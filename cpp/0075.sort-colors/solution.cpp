// Created by Po-Yeh Chen at 2025/01/18 10:06
// leetgo: 1.4.13
// https://leetcode.com/problems/sort-colors/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
  public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int r = 0, w = 0, b = n - 1;

        while (w <= b) {
            if (nums[w] == 0) {
                swap(nums[w], nums[r]);
                w++;
                r++;
            } else if (nums[w] == 1) {
                w++;
            } else {
                swap(nums[w], nums[b]);
                b--;
            }
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    /* auto res = obj->sortColors(nums); */
    LeetCodeIO::print(out_stream, nums);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
