// Created by Po-Yeh Chen at 2025/01/29 15:03
// leetgo: 1.4.13
// https://leetcode.com/problems/sum-of-subarray-minimums/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int sumSubarrayMins(vector<int>& arr) {
        const int64_t MOD = 1e9 + 7;
        int64_t sum = 0;
        vector<int> st;

        st.reserve(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.back()] > arr[i]) {
                int64_t curr = st.back();
                st.pop_back();
                int64_t prev = st.empty() ? -1 : st.back();
                int64_t next = i;
                int64_t count = (curr - prev) * (next - curr) % MOD;
                sum = (sum + (count * arr[curr]) % MOD) % MOD;
            }
            st.push_back(i);
        }
        while (!st.empty()) {
            int64_t curr = st.back();
            st.pop_back();
            int64_t prev = st.empty() ? -1 : st.back();
            int64_t count = (curr - prev) * (arr.size() - curr) % MOD;
            sum = (sum + (count * arr[curr]) % MOD) % MOD;
        }

        return static_cast<int>(sum);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> arr;
    LeetCodeIO::scan(cin, arr);

    Solution* obj = new Solution();
    auto res = obj->sumSubarrayMins(arr);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
