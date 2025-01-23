// Created by Po-Yeh Chen at 2025/01/21 08:38
// leetgo: 1.4.13
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> min_heap;

        for (int num : nums) {
            if (min_heap.size() < k || num > min_heap.top()) {
                min_heap.push(num);
                if (min_heap.size() > k) {
                    min_heap.pop();
                }
            }
        }
        return min_heap.top();
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
    auto res = obj->findKthLargest(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
