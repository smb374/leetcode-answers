// Created by Po-Yeh Chen at 2025/01/25 08:52
// leetgo: 1.4.13
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t sz = numbers.size();
        int lo = 0, hi = sz - 1;

        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];

            if (sum < target) {
                lo++;
            } else if (sum > target) {
                hi--;
            } else {
                return {lo + 1, hi + 1};
            }
        }

        return {-1, -1};
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> numbers;
    LeetCodeIO::scan(cin, numbers);
    int target;
    LeetCodeIO::scan(cin, target);

    Solution* obj = new Solution();
    auto res = obj->twoSum(numbers, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
