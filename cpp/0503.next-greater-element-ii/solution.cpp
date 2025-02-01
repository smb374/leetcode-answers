// Created by Po-Yeh Chen at 2025/01/28 20:17
// leetgo: 1.4.13
// https://leetcode.com/problems/next-greater-element-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> st, res(sz, -1);
        st.reserve(sz);
        for (int i = 0; i < 2 * sz; i++) {
            int curr = nums[i % sz];
            while (!st.empty() && nums[st.back()] < curr) {
                res[st.back()] = curr;
                st.pop_back();
            }
            st.push_back(i % sz);
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
    auto res = obj->nextGreaterElements(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
