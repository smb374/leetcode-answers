// Created by Po-Yeh Chen at 2025/01/29 10:15
// leetgo: 1.4.13
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        size_t m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;
        int lo = 0, hi = m;

        while (lo <= hi) {
            int i = lo + ((hi - lo) >> 1);
            int j = half - i;

            int l1 = i > 0 ? nums1[i - 1] : INT_MIN;
            int r1 = i < m ? nums1[i] : INT_MAX;
            int l2 = j > 0 ? nums2[j - 1] : INT_MIN;
            int r2 = j < n ? nums2[j] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (total & 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) * 0.5;
                }
            } else if (l1 > r2) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }

        return -1;
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
    auto res = obj->findMedianSortedArrays(nums1, nums2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
