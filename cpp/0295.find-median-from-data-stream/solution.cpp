// Created by Po-Yeh Chen at 2025/01/23 10:15
// leetgo: 1.4.13
// https://leetcode.com/problems/find-median-from-data-stream/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

// @lc code=begin

class MedianFinder {
  private:
    priority_queue<int, vector<int>, less<>> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;

  public:
    MedianFinder() {}

    void addNum(int num) {
        max_heap.push(num);

        min_heap.push(max_heap.top());
        max_heap.pop();

        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        return max_heap.size() > min_heap.size()
                   ? max_heap.top()
                   : (max_heap.top() + min_heap.top()) * 0.5;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    MedianFinder* obj;
    const unordered_map<string, function<void()>> methods = {
        {"MedianFinder",
         [&]() {
             cin.ignore();
             obj = new MedianFinder();
             out_stream << "null,";
         }},
        {"addNum",
         [&]() {
             int num;
             LeetCodeIO::scan(cin, num);
             cin.ignore();
             obj->addNum(num);
             out_stream << "null,";
         }},
        {"findMedian",
         [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->findMedian());
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
