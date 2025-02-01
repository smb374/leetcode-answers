// Created by Po-Yeh Chen at 2025/01/23 18:37
// leetgo: 1.4.13
// https://leetcode.com/problems/top-k-frequent-elements/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    using element = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;
        priority_queue<element, vector<element>, greater<>> min_heap;

        res.reserve(k);
        for (const int n : nums) {
            freq[n]++;
        }

        for (auto& entry : freq) {
            auto [val, freq] = entry;
            if (min_heap.size() < k || freq > min_heap.top().first) {
                min_heap.emplace(freq, val);
                if (min_heap.size() > k) {
                    min_heap.pop();
                }
            }
        }

        while (!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
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
    auto res = obj->topKFrequent(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
