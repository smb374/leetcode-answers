// Created by Po-Yeh Chen at 2025/01/23 18:13
// leetgo: 1.4.13
// https://leetcode.com/problems/contains-duplicate/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <unordered_map>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        size_t sz = nums.size();
        unordered_set<int> seen;
        seen.reserve(sz);

        for (const int n : nums) {
            if (!seen.insert(n).second) {
                return true;
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

    Solution* obj = new Solution();
    auto res = obj->containsDuplicate(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
