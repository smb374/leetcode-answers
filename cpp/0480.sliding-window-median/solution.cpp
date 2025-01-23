// Created by Po-Yeh Chen at 2025/01/20 09:04
// leetgo: 1.4.13
// https://leetcode.com/problems/sliding-window-median/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();
        unordered_map<int64_t, int64_t> lazy_pop;
        priority_queue<int64_t, vector<int64_t>, less<>> max_heap;
        priority_queue<int64_t, vector<int64_t>, greater<>> min_heap;

        for (int i = 0; i < k; i++) {
            max_heap.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        for (int i = k; i <= n; i++) {
            if (k & 1) {
                res.push_back(max_heap.top());
            } else {
                res.push_back((max_heap.top() + min_heap.top()) * 0.5);
            }

            if (i == n)
                break;

            int p = nums[i - k], q = nums[i], bal = 0;

            if (p <= max_heap.top()) {
                bal--;
                if (p == max_heap.top()) {
                    max_heap.pop();
                } else {
                    lazy_pop[p]++;
                }
            } else {
                bal++;
                if (p == min_heap.top()) {
                    min_heap.pop();
                } else {
                    lazy_pop[p]++;
                }
            }

            if (!max_heap.empty() && q <= max_heap.top()) {
                bal++;
                max_heap.push(q);
            } else {
                bal--;
                min_heap.push(q);
            }

            if (bal < 0) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            } else if (bal > 0) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }

            while (!max_heap.empty() && lazy_pop[max_heap.top()] > 0) {
                lazy_pop[max_heap.top()]--;
                max_heap.pop();
            }
            while (!min_heap.empty() && lazy_pop[min_heap.top()] > 0) {
                lazy_pop[min_heap.top()]--;
                min_heap.pop();
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->medianSlidingWindow(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
