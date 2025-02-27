// Created by Po-Yeh Chen at 2025/01/18 10:46
// leetgo: 1.4.13
// https://leetcode.com/problems/happy-number/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
    int next(int n) {
        int res = 0;
        while (n) {
            int dig = n % 10;
            res += dig * dig;
            n /= 10;
        }
        return res;
    }

  public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(slow);

        while (slow != fast && fast != 1) {
            slow = next(slow);
            fast = next(next(fast));
        }

        return fast == 1;
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
