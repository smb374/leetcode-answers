// Created by Po-Yeh Chen at 2025/01/21 08:24
// leetgo: 1.4.13
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

// @lc code=begin

class KthLargest {
  private:
    priority_queue<int, vector<int>, greater<>> min_heap;
    const int k;

  public:
    KthLargest(int k, vector<int>& nums)
        : k(k), min_heap(nums.begin(), nums.end()) {
        while (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    int add(int val) {
        if (min_heap.size() < k || val > min_heap.top()) {
            min_heap.push(val);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        return min_heap.top();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    KthLargest* obj;
    const unordered_map<string, function<void()>> methods = {
        {"KthLargest",
         [&]() {
             int k;
             LeetCodeIO::scan(cin, k);
             cin.ignore();
             vector<int> nums;
             LeetCodeIO::scan(cin, nums);
             cin.ignore();
             int numsSize;
             LeetCodeIO::scan(cin, numsSize);
             cin.ignore();
             obj = new KthLargest(k, nums, numsSize);
             out_stream << "null,";
         }},
        {"add",
         [&]() {
             int val;
             LeetCodeIO::scan(cin, val);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->add(val));
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
