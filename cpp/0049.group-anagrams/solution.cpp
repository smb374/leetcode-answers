// Created by Po-Yeh Chen at 2025/01/23 18:27
// leetgo: 1.4.13
// https://leetcode.com/problems/group-anagrams/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            string s(strs[i]);
            sort(s.begin(), s.end());
            groups[s].push_back(strs[i]);
        }

        for (auto& entry : groups) {
            res.push_back(entry.second);
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> strs;
    LeetCodeIO::scan(cin, strs);

    Solution* obj = new Solution();
    auto res = obj->groupAnagrams(strs);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
