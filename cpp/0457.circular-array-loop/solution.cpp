// Created by Po-Yeh Chen at 2025/01/18 11:03
// leetgo: 1.4.13
// https://leetcode.com/problems/circular-array-loop/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<bool> seen;
    int next(int i, const vector<int>& nums) {
        int n = nums.size();
        int res = (i + nums[i]) % n;
        while (res < 0)
            res += n;
        return res;
    }
    int floyd(const vector<int>& nums, int i) {
        int slow = next(i, nums);
        int fast = next(slow, nums);

        while (slow != fast) {
            slow = next(slow, nums);
            fast = next(next(fast, nums), nums);
        }

        int len = 1;
        bool equal_sign = true;
        fast = next(slow, nums);
        seen[fast] = true;
        while (fast != slow) {
            bool sign = nums[fast] >= 0;
            fast = next(fast, nums);
            seen[fast] = true;
            equal_sign = equal_sign && (sign == nums[fast] >= 0);
            len++;
        }

        return equal_sign ? len : 1;
    }

  public:
    bool circularArrayLoop(vector<int>& nums) {
        seen = vector(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            if (seen[i])
                continue;
            if (floyd(nums, i) > 1) {
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
    auto res = obj->circularArrayLoop(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
