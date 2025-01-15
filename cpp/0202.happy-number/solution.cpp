// Created by Po-Yeh Chen at 2025/01/15 12:25
// leetgo: 1.4.13
// https://leetcode.com/problems/happy-number/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
    unordered_map<int, int> seen;
    int next(int n) {
        if (seen.count(n)) {
            return seen[n];
        }
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        seen[n] = sum;
        return sum;
    }

  public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1) {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == fast && fast != 1) {
                return false;
            }
        }

        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution* obj = new Solution();
    auto res = obj->isHappy(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
