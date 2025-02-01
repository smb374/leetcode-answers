// Created by Po-Yeh Chen at 2025/01/23 08:43
// leetgo: 1.4.13
// https://leetcode.com/problems/subsets/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<int> path;
    void backtrack(int idx, vector<vector<int>>& res, const vector<int>& nums) {
        if (idx == nums.size()) {
            res.emplace_back(path);
            return;
        }

        path.push_back(nums[idx]);
        backtrack(idx + 1, res, nums);
        path.pop_back();
        backtrack(idx + 1, res, nums);
    }

  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.reserve(nums.size());
        vector<vector<int>> res;
        backtrack(0, res, nums);
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
