// Created by Po-Yeh Chen at 2025/01/21 09:28
// leetgo: 1.4.13
// https://leetcode.com/problems/reorganize-string/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    using element = pair<int, char>;
    string reorganizeString(string s) {
        int freq[26] = {0}, n = s.length(), top = 0;
        string res(n, ' ');
        priority_queue<element, vector<element>, less<>> max_heap;

        for (const char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                max_heap.emplace(freq[i], i + 'a');
            }
        }

        while (!max_heap.empty()) {
            auto [f1, c1] = max_heap.top();
            max_heap.pop();

            if (top == 0 || c1 != res[top - 1]) {
                res[top++] = c1;
                if (--f1 > 0) {
                    max_heap.emplace(f1, c1);
                }
            } else if (max_heap.empty()) {
                return "";
            } else {
                auto [f2, c2] = max_heap.top();
                max_heap.pop();

                res[top++] = c2;
                if (--f2 > 0) {
                    max_heap.emplace(f2, c2);
                }
                max_heap.emplace(f1, c1);
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
    auto res = obj->reorganizeString(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
