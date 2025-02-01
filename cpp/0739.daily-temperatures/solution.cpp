// Created by Po-Yeh Chen at 2025/01/27 08:51
// leetgo: 1.4.13
// https://leetcode.com/problems/daily-temperatures/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <stack>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t sz = temperatures.size();
        vector<int> res(sz, 0);
        stack<int> st;

        for (int i = 0; i < sz; i++) {
            int t = temperatures[i];
            while (!st.empty() && temperatures[st.top()] < t) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> temperatures;
    LeetCodeIO::scan(cin, temperatures);

    Solution* obj = new Solution();
    auto res = obj->dailyTemperatures(temperatures);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
