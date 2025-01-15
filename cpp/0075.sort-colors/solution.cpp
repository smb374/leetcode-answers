// Created by Po-Yeh Chen at 2025/01/15 12:20
// leetgo: 1.4.13
// https://leetcode.com/problems/sort-colors/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
  public:
    void sortColors(vector<int>& nums) {
        // red = 0, white = 1, blue = 2
        int i = 0, j = nums.size() - 1, k = 0;
        while (k <= j) {
            if (nums[k] == 0) {
                swap(nums[i++], nums[k++]);
            } else if (nums[k] == 1) {
                k++;
            } else {
                swap(nums[j--], nums[k]);
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
    auto res = obj->sortColors(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
