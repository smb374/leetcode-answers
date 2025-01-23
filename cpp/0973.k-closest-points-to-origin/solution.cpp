// Created by Po-Yeh Chen at 2025/01/21 08:53
// leetgo: 1.4.13
// https://leetcode.com/problems/k-closest-points-to-origin/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    int distance2(int x, int y) { return x * x + y * y; }

  public:
    using element = pair<int, int>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        res.reserve(k);
        priority_queue<element, vector<element>, less<>> max_heap;

        for (int i = 0; i < points.size(); i++) {
            int d = distance2(points[i][0], points[i][1]);
            if (max_heap.size() < k || d < max_heap.top().first) {
                max_heap.emplace(d, i);
                if (max_heap.size() > k) {
                    max_heap.pop();
                }
            }
        }

        while (!max_heap.empty()) {
            res.emplace_back(points[max_heap.top().second]);
            max_heap.pop();
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> points;
    LeetCodeIO::scan(cin, points);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->kClosest(points, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
