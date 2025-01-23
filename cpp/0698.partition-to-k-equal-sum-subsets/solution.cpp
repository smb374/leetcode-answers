// Created by Po-Yeh Chen at 2025/01/22 11:38
// leetgo: 1.4.13
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    int16_t visited;
    unordered_map<int16_t, bool> memo;

    inline bool get_idx(int idx) { return ((visited >> idx) & 1) == 1; }
    inline void toggle_idx(int idx) { visited ^= (1 << idx); }
    bool backtrack(int idx, int count, int current, const int& target,
                   const int& k, const vector<int>& nums) {
        if (count == k - 1) {
            return true;
        } else if (current > target) {
            return false;
        } else if (current == target) {
            bool result = backtrack(0, count + 1, 0, target, k, nums);
            memo[visited] = result;
            return result;
        } else if (memo.find(visited) != memo.end()) {
            return memo[visited];
        }

        for (int i = idx; i < nums.size(); i++) {
            if (get_idx(i))
                continue;

            toggle_idx(i);
            if (backtrack(i + 1, count, current + nums[i], target, k, nums)) {
                memo[visited] = true;
                return true;
            }
            toggle_idx(i);
        }

        memo[visited] = false;
        return false;
    }

  public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        if (total % k != 0) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<>{});

        int target = total / k;
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
