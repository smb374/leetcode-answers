// Created by Po-Yeh Chen at 2025/01/24 09:07
// leetgo: 1.4.13
// https://leetcode.com/problems/product-of-array-except-self/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <vector>
using namespace std;

// @lc code=begin

void print_vec(const vector<int>& v) {
    printf("v:");
    for (const int e : v) {
        printf(" %d", e);
    }
    printf("\n");
}
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> res(n, 1);
        int suffix = 1;

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
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
    auto res = obj->productExceptSelf(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
