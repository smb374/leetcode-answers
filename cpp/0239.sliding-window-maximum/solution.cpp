// Created by Po-Yeh Chen at 2025/01/17 09:34
// leetgo: 1.4.13
// https://leetcode.com/problems/sliding-window-maximum/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        for (int i = k; i < n; i++) {
            if (dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->maxSlidingWindow(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
