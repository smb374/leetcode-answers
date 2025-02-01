// Created by Po-Yeh Chen at 2025/01/23 08:58
// leetgo: 1.4.13
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <unordered_map>
#include <variant>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    int16_t visited;
    unordered_map<int16_t, bool> memo;
    bool backtrack(int idx, int count, int current, const int& target,
                   const int& k, const vector<int>& nums) {
        if (count == k - 1) {
            return true;
        }
        if (current > target) {
            return false;
        }
        if (current == target) {
            memo[visited] = backtrack(0, count + 1, 0, target, k, nums);
            return memo[visited];
        }
        if (memo.find(visited) != memo.end()) {
            return memo[visited];
        }

        for (int i = idx; i < nums.size(); i++) {
            if (((visited >> i) & 1) == 1)
                continue;
            visited ^= 1 << i;
            if (backtrack(i + 1, count, current + nums[i], target, k, nums)) {
                memo[visited] = true;
                return true;
            }
            visited ^= 1 << i;
        }
        memo[visited] = false;
        return false;
    }

  public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (const int v : nums) {
            total += v;
        }
        if (total % k != 0) {
            return false;
        }
        int target = total / k;

        sort(nums.begin(), nums.end(), greater<>{});
        return backtrack(0, 0, 0, target, k, nums);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->canPartitionKSubsets(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
