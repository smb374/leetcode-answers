// Created by Po-Yeh Chen at 2025/01/27 08:18
// leetgo: 1.4.13
// https://leetcode.com/problems/valid-parentheses/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <stack>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;

        stack<char> st;
        st.push(' ');

        for (const char c : s) {
            switch (c) {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;
            case ')':
                if (st.top() != '(')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.top() != '[')
                    return false;
                st.pop();
                break;
            case '}':
                if (st.top() != '{')
                    return false;
                st.pop();
                break;
            default:
                break;
            }
        }

        return st.size() == 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution* obj = new Solution();
    auto res = obj->isValid(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
