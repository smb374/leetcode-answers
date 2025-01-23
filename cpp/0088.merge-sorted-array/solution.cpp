// Created by Po-Yeh Chen at 2025/01/20 09:12
// leetgo: 1.4.13
// https://leetcode.com/problems/merge-sorted-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n, 0);
        int i = 0, j = 0, top = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                res[top++] = nums1[i++];
            } else {
                res[top++] = nums2[j++];
            }
        }

        while (i < m) {
            res[top++] = nums1[i++];
        }
        while (j < n) {
            res[top++] = nums2[j++];
        }

        res.swap(nums1);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    int m;
    LeetCodeIO::scan(cin, m);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution* obj = new Solution();
    obj->merge(nums1, m, nums2, n);
    LeetCodeIO::print(out_stream, nums1);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
