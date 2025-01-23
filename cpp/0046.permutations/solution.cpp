// Created by Po-Yeh Chen at 2025/01/22 10:59
// leetgo: 1.4.13
// https://leetcode.com/problems/permutations/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<bool> visited;
    vector<int> path;

    void backtrack(int depth, vector<vector<int>>& res,
                   const vector<int>& nums) {
        // Base case: reached leaf, push path to result.
        if (depth == nums.size()) {
            res.emplace_back(path);
            return;
        }
        // Normal case: Find a index that's not visited and explore it.
        for (int i = 0; i < nums.size(); i++) {
            // Skip visited index
            if (visited[i])
                continue;
            // Explore index.
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(depth + 1, res, nums);
            // Un-explore index.
            visited[i] = false;
            path.pop_back();
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
