// Created by Po-Yeh Chen at 2025/01/21 08:47
// leetgo: 1.4.13
// https://leetcode.com/problems/meeting-rooms-ii/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<>> min_heap;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        for (auto& iv : intervals) {
            if (!min_heap.empty() && iv[0] >= min_heap.top()) {
                min_heap.pop();
            }
            min_heap.push(iv[1]);
        }

        return min_heap.size();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> intervals;
    LeetCodeIO::scan(cin, intervals);

    Solution* obj = new Solution();
    auto res = obj->minMeetingRooms(intervals);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
