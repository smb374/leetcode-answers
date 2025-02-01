// Created by Po-Yeh Chen at 2025/01/28 19:40
// leetgo: 1.4.13
// https://leetcode.com/problems/next-greater-element-i/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table;
        vector<int> st, res(nums1.size(), -1);

        st.reserve(nums2.size());
        // 1. Find next greater element in nums2.
        for (const int curr : nums2) {
            while (!st.empty() && st.back() < curr) {
                table[st.back()] = curr;
                st.pop_back();
            }
            st.push_back(curr);
        }
        // 2. Fill the results
        for (int i = 0; i < nums1.size(); i++) {
            if (table.count(nums1[i])) {
                res[i] = table[nums1[i]];
            }
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);

    Solution* obj = new Solution();
    auto res = obj->nextGreaterElement(nums1, nums2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
