// Created by Po-Yeh Chen at 2025/01/26 10:12
// leetgo: 1.4.13
// https://leetcode.com/problems/sliding-window-maximum/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    using element = pair<int, int>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        size_t sz = nums.size();
        vector<int> res;
        priority_queue<element, vector<element>, less<>> max_heap;

        for (int i = 0; i < k; i++) {
            max_heap.emplace(nums[i], i);
        }

        res.push_back(max_heap.top().first);

        for (int i = k; i < sz; i++) {
            while (!max_heap.empty() && max_heap.top().second <= i - k) {
                max_heap.pop();
            }
            max_heap.emplace(nums[i], i);
            res.push_back(max_heap.top().first);
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
