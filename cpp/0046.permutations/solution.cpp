// Created by Po-Yeh Chen at 2025/01/23 08:48
// leetgo: 1.4.13
// https://leetcode.com/problems/permutations/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<int> path;
    vector<bool> visited;

    void backtrack(int depth, vector<vector<int>>& res,
                   const vector<int>& nums) {
        if (depth == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(depth + 1, res, nums);
            path.pop_back();
            visited[i] = false;
        }
    }

  public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.reserve(nums.size());
        visited = vector(nums.size(), false);
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
    auto res = obj->permute(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
