// Created by Po-Yeh Chen at 2025/01/18 09:03
// leetgo: 1.4.13
// https://leetcode.com/problems/employee-free-time/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

// Definition for an Interval.
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
using event = pair<int, int>;
class Solution {
  public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        vector<event> events;
        for (int i = 0; i < schedule.size(); i++) {
            for (Interval& iv : schedule[i]) {
                events.emplace_back(iv.start, -1);
                events.emplace_back(iv.end, 1);
            }
        }

        sort(events.begin(), events.end(), [](const event& a, const event& b) {
            return a.first != b.first ? a.first < b.first : a.second < b.second;
        });

        int prev = -1, bal = 0;

        for (const event& ev : events) {
            if (!bal && prev >= 0) {
                res.emplace_back(prev, ev.first);
            }
            bal -= ev.second;
            prev = ev.first;
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
