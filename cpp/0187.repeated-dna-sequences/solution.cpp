// Created by Po-Yeh Chen at 2025/01/17 10:08
// leetgo: 1.4.13
// https://leetcode.com/problems/repeated-dna-sequences/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <string_view>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    constexpr int to_int(const char c) {
        switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default:
            return -1;
        }
    }

  public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length(), h = 0;
        unordered_set<int> seen, used;
        vector<string> res;
        string_view sv(s);

        for (int i = 0; i < 10; i++) {
            h = (h << 2) | to_int(s[i]);
        }
        seen.insert(h);
        for (int i = 1; i <= n - 10; i++) {
            h = ((h << 2) | to_int(s[i + 10 - 1])) & 0xFFFFF;
            if (used.count(h))
                continue;

            if (!seen.insert(h).second) {
                res.emplace_back(sv.substr(i, 10));
                used.insert(h);
            }
        }

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
    auto res = obj->findRepeatedDnaSequences(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
