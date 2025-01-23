// Created by Po-Yeh Chen at 2025/01/22 09:58
// leetgo: 1.4.13
// https://leetcode.com/problems/random-pick-with-weight/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <iterator>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  private:
    vector<int> prefix_sum;

  public:
    Solution(vector<int>& w) : prefix_sum(w.size() + 1) {
        for (int i = 1; i <= w.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + w[i - 1];
        }
    }

    int pickIndex() {
        double sample = (double)rand() / RAND_MAX;
        double target = prefix_sum.back() * sample;

        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), target);
        return it - prefix_sum.begin() - 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    Solution* obj;
    const unordered_map<string, function<void()>> methods = {
        {"Solution",
         [&]() {
             vector<int> w;
             LeetCodeIO::scan(cin, w);
             cin.ignore();
             int wSize;
             LeetCodeIO::scan(cin, wSize);
             cin.ignore();
             obj = new Solution(w, wSize);
             out_stream << "null,";
         }},
        {"pickIndex",
         [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->pickIndex());
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
