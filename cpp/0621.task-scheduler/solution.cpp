// Created by Po-Yeh Chen at 2025/01/18 09:24
// leetgo: 1.4.13
// https://leetcode.com/problems/task-scheduler/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0}, max_freq = 0, max_count = 0, sz = tasks.size();
        for (const char c : tasks) {
            int idx = c - 'A';
            freq[idx]++;
            max_freq = max(max_freq, freq[idx]);
        }
        for (int i = 0; i < 26; i++) {
            max_count += freq[i] == max_freq;
        }

        return max(sz, (n + 1) * (max_freq - 1) + max_count);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<char> tasks;
    LeetCodeIO::scan(cin, tasks);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution* obj = new Solution();
    auto res = obj->leastInterval(tasks, n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
