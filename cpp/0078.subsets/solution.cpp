// Created by Po-Yeh Chen at 2025/01/22 10:53
// leetgo: 1.4.13
// https://leetcode.com/problems/subsets/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    void backtrack(int idx, vector<int>& path, vector<vector<int>>& res,
                   const vector<int>& nums) {
        if (idx == nums.size()) {
            res.emplace_back(path);
            return;
        }
        // Case 1. take current element.
        path.push_back(nums[idx]);
        backtrack(idx + 1, path, res, nums);
        path.pop_back();
        // Case 2. skip current element.
        backtrack(idx + 1, path, res, nums);
    }

  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        path.reserve(nums.size());
        backtrack(0, path, res, nums);

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    auto res = obj->subsets(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
