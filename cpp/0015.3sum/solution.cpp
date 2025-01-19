// Created by Po-Yeh Chen at 2025/01/18 09:32
// leetgo: 1.4.13
// https://leetcode.com/problems/3sum/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int x = nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                int y = nums[j], z = nums[k];
                int sum = x + y + z;

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    res.push_back({x, y, z});
                    while (j < k && nums[j] == y) {
                        j++;
                    }
                    while (j < k && nums[k] == z) {
                        k--;
                    }
                }
            }
        }

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
    auto res = obj->threeSum(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
