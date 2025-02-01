// Created by Po-Yeh Chen at 2025/01/23 10:42
// leetgo: 1.4.13
// https://leetcode.com/problems/jump-game/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

enum State { GOOD, BAD, UNKNOWN };
class Solution {
  public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), max_pos = 0;
        for (int i = 0; i <= max_pos; i++) {
            max_pos = max(max_pos, i + nums[i]);
            if (max_pos >= n - 1)
                return true;
        }

        return false;
        /* vector<State> memo(n, UNKNOWN); */
        /* memo[n - 1] = GOOD; */
        /**/
        /* for (int i = n - 2; i >= 0; i--) { */
        /*     int max_jump = min(i + nums[i], n - 1); */
        /*     for (int j = i + 1; j <= max_jump; j++) { */
        /*         if (memo[j] == GOOD) { */
        /*             memo[i] = GOOD; */
        /*             break; */
        /*         } */
        /*     } */
        /* } */

        /* return memo[0] == GOOD; */
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution* obj = new Solution();
    auto res = obj->canJump(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
