// Created by Po-Yeh Chen at 2025/01/27 08:24
// leetgo: 1.4.13
// https://leetcode.com/problems/min-stack/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
#include <stack>
using namespace std;

// @lc code=begin

class MinStack {
  private:
    stack<int> data;
    stack<int> minst;

  public:
    MinStack() : data() {}

    void push(int val) {
        data.push(val);
        if (minst.empty() || val <= minst.top()) {
            minst.push(val);
        }
    }

    void pop() {
        if (data.empty())
            return;

        if (!minst.empty() && minst.top() == data.top()) {
            data.pop();
            minst.pop();
        } else {
            data.pop();
        }
    }

    int top() { return data.top(); }

    int getMin() { return minst.top(); }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    MinStack* obj;
    const unordered_map<string, function<void()>> methods = {
        {"MinStack",
         [&]() {
             cin.ignore();
             obj = new MinStack();
             out_stream << "null,";
         }},
        {"push",
         [&]() {
             int val;
             LeetCodeIO::scan(cin, val);
             cin.ignore();
             obj->push(val);
             out_stream << "null,";
         }},
        {"pop",
         [&]() {
             cin.ignore();
             obj->pop();
             out_stream << "null,";
         }},
        {"top",
         [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->top());
             out_stream << ',';
         }},
        {"getMin",
         [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getMin());
             out_stream << ',';
         }},
    };
    cin >> ws;
    out_stream << '[';
    for (auto&& method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
