// Created by Po-Yeh Chen at 2025/01/18 09:44
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
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        priority_queue<int, vector<int>, greater<>> pq;

        for (int i = 0; i < intervals.size(); i++) {
            if (!pq.empty() && intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }

        return pq.size();
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
