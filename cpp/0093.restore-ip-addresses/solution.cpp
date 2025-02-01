// Created by Po-Yeh Chen at 2025/01/23 12:51
// leetgo: 1.4.13
// https://leetcode.com/problems/restore-ip-addresses/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<string> res;

  public:
    // Check if the segment is valid
    // - length should be in [1, 3]
    // - no preceding 0 unless length is 1
    // - numeric value should be <= 255
    bool valid(const string& seg) {
        size_t n = seg.length();
        return (n > 0 && n <= 3) && (n == 1 || seg[0] != '0') &&
               (stoi(seg) <= 255);
    }

    void backtrack(size_t idx, size_t dots, string path, const string& s) {
        if (dots == 3) {
            if (valid(s.substr(idx))) {
                res.push_back(path + s.substr(idx));
            }
            return;
        }
        size_t limit = min(idx + 3, s.length());
        // 3 choises for 111255:
        // - 1.(11255)
        // - 11.(1255)
        // - 111.(255)
        // Parentheses means next process region
        for (size_t i = idx; i < limit; i++) {
            if (!valid(s.substr(idx, i - idx + 1))) {
                continue;
            }
            path.push_back(s[i]);
            path.push_back('.');
            backtrack(i + 1, dots + 1, path, s);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string path;
        backtrack(0, 0, path, s);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->restoreIpAddresses(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
