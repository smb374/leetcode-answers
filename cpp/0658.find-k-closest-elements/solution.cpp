// Created by Po-Yeh Chen at 2025/01/17 10:04
// leetgo: 1.4.13
// https://leetcode.com/problems/find-k-closest-elements/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (x - arr[mid] > arr[mid + k] - x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return vector(arr.begin() + lo, arr.begin() + lo + k);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> arr;
    LeetCodeIO::scan(cin, arr);
    int k;
    LeetCodeIO::scan(cin, k);
    int x;
    LeetCodeIO::scan(cin, x);

    Solution* obj = new Solution();
    auto res = obj->findClosestElements(arr, k, x);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
