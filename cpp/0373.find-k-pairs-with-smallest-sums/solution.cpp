// Created by Po-Yeh Chen at 2025/01/23 09:15
// leetgo: 1.4.13
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    using element = pair<int, pair<int, int>>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        set<pair<int, int>> used;
        priority_queue<element, vector<element>, greater<>> min_heap;
        vector<vector<int>> res;

        used.emplace(0, 0);
        min_heap.push({nums1[0] + nums2[0], {0, 0}});
        res.reserve(k);

        while (k-- && !min_heap.empty()) {
            element top = min_heap.top();
            min_heap.pop();
            auto [i, j] = top.second;
            res.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size() && used.find({i + 1, j}) == used.end()) {
                used.emplace(i + 1, j);
                min_heap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            }
            if (j + 1 < nums2.size() && used.find({i, j + 1}) == used.end()) {
                used.emplace(i, j + 1);
                min_heap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->kSmallestPairs(nums1, nums2, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
