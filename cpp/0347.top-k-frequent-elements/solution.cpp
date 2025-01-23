// Created by Po-Yeh Chen at 2025/01/21 08:41
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            min_heap;
        vector<int> res;
        res.reserve(k);

        for (int num : nums) {
            freq[num]++;
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
