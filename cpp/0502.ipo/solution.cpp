// Created by Po-Yeh Chen at 2025/01/20 08:55
// leetgo: 1.4.13
// https://leetcode.com/problems/ipo/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size(), top = 0;
        vector<pair<int, int>> projects(n);
        priority_queue<int> max_heap;
        for (int i = 0; i < n; i++) {
            projects[i].first = capital[i];
            projects[i].second = profits[i];
        }

        sort(projects.begin(), projects.end());

        for (int i = 0; i < k; i++) {
            while (top < n && projects[top].first <= w) {
                max_heap.push(projects[top].second);
                top++;
            }

            if (max_heap.empty())
                break;

            w += max_heap.top();
            max_heap.pop();
        }

        return w;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int k;
    LeetCodeIO::scan(cin, k);
    int w;
    LeetCodeIO::scan(cin, w);
    vector<int> profits;
    LeetCodeIO::scan(cin, profits);
    vector<int> capital;
    LeetCodeIO::scan(cin, capital);

    Solution* obj = new Solution();
    auto res = obj->findMaximizedCapital(k, w, profits, capital);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
