// Created by Po-Yeh Chen at 2025/01/21 09:10
// leetgo: 1.4.13
// https://leetcode.com/problems/employee-free-time/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Interval {
  public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

// @lc code=begin

class Solution {
  public:
    using element = pair<int, pair<int, int>>;
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<element, vector<element>, greater<>> min_heap;
        vector<Interval> res;
        int anchor = numeric_limits<int>::max();
        for (int i = 0; i < schedule.size(); i++) {
            min_heap.push({schedule[i][0].start, {i, 0}});
            anchor = min(anchor, schedule[i][0].start);
        }

        while (!min_heap.empty()) {
            element top = min_heap.top();
            min_heap.pop();
            int start = top.first;
            auto [eidx, idx] = top.second;
            if (anchor < start) {
                res.emplace_back(anchor, start);
            }
            anchor = max(anchor, schedule[eidx][idx].end);
            if (++idx < schedule[eidx].size()) {
                min_heap.push({schedule[eidx][idx].start, {eidx, idx}});
            }
        }

        return res;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int schedule;
    LeetCodeIO::scan(cin, schedule);

    Solution* obj = new Solution();
    auto res = obj->employeeFreeTime(schedule);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
