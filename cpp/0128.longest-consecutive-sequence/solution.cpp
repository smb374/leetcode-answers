// Created by Po-Yeh Chen at 2025/01/24 09:37
// leetgo: 1.4.13
// https://leetcode.com/problems/longest-consecutive-sequence/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <unordered_set>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int sz = nums.size();
        int curr = 1, mlen = 1;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < sz; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    curr++;
                } else {
                    mlen = max(mlen, curr);
                    curr = 1;
                }
            }
        }

        return max(curr, mlen);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    auto res = obj->longestConsecutive(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
