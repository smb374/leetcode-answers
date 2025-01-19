// Created by Po-Yeh Chen at 2025/01/18 10:12
// leetgo: 1.4.13
// https://leetcode.com/problems/reverse-words-in-a-string/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;

// @lc code=begin

class Solution {
  public:
    string reverseWords(string s) {
        int n = s.length(), top = n;
        string res(n, ' ');
        int i = 0, j = 0;
        while (j < n && s[j] == ' ')
            j++;
        i = j;
        while (j < n) {
            while (j < n && s[j] != ' ')
                j++;
            int size = j - i;
            for (int k = 0; k < size; k++) {
                res[top - size + k] = s[i + k];
            }
            top -= size + 1;
            while (j < n && s[j] == ' ')
                j++;
            i = j;
        }

        return res.substr(top + 1);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->reverseWords(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
