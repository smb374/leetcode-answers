// Created by Po-Yeh Chen at 2025/01/15 12:27
// leetgo: 1.4.13
// https://leetcode.com/problems/circular-array-loop/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<bool> used;
    int next(vector<int>& nums, int i) {
        return (i + nums[i] + nums.size()) % nums.size();
    }
    int floyd(vector<int>& nums, int i) {
        int slow = next(nums, i);
        int fast = next(nums, next(nums, i));
        while (slow != fast) {
            slow = next(nums, slow);
            fast = next(nums, next(nums, fast));
        }

        int size = 1;
        fast = next(nums, slow);
        bool equal_sign = true;
        used[fast] = true;
        while (slow != fast) {
            bool osig = nums[fast] >= 0;
            fast = next(nums, fast);
            equal_sign = equal_sign && (osig == (nums[fast] >= 0));
            used[fast] = true;
            size++;
        }

        return equal_sign ? size : 1;
    }

  public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        used = vector(n, false);
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            int size = floyd(nums, i);
            if (size > 1)
                return true;
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
    auto res = obj->circularArrayLoop(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
