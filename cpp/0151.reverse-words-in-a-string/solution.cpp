// Created by Po-Yeh Chen at 2025/01/15 12:20
// leetgo: 1.4.13
// https://leetcode.com/problems/reverse-words-in-a-string/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    string reverseWords(string s) {
        int n = s.length(), i = 0, j, top = s.length();
        string res(n, ' ');
        while (s[i] == ' ')
            i++;

        j = i;
        while (j < n) {
            if (s[j] != ' ') {
                j++;
                continue;
            } else {
                int size = j - i;
                for (int k = 0; k < size; k++) {
                    res[top - size + k] = s[i + k];
                }
                top -= size + 1;
                while (s[j] == ' ')
                    j++;
                i = j;
            }
        }
        int size = j - i;
        for (int k = 0; k < size; k++) {
            res[top - size + k] = s[i + k];
        }

        int start = 0;
        while (res[start] == ' ')
            start++;

        return res.substr(start);
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
