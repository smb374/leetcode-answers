// Created by Po-Yeh Chen at 2025/01/23 18:18
// leetgo: 1.4.13
// https://leetcode.com/problems/valid-anagram/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int sfreq[26] = {0};
        int tfreq[26] = {0};

        for (size_t i = 0; i < s.size(); i++) {
            sfreq[s[i] - 'a']++;
            tfreq[t[i] - 'a']++;
        }

        for (size_t i = 0; i < 26; i++) {
            if (sfreq[i] != tfreq[i])
                return false;
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    string t;
    LeetCodeIO::scan(cin, t);

    Solution* obj = new Solution();
    auto res = obj->isAnagram(s, t);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
