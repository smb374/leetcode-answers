// Created by Po-Yeh Chen at 2025/01/27 08:33
// leetgo: 1.4.13
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

// @lc code=begin

class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& tok : tokens) {
            switch (tok[0]) {
            case '+': {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
                break;
            }
            case '-': {
                if (tok.length() > 1) {
                    st.push(stoi(tok));
                } else {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    st.push(a - b);
                }
                break;
            }
            case '*': {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
                break;
            }
            case '/': {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
                break;
            }
            default:
                st.push(stoi(tok));
                break;
            }
        }

        return st.top();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> tokens;
    LeetCodeIO::scan(cin, tokens);

    Solution* obj = new Solution();
    auto res = obj->evalRPN(tokens);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
