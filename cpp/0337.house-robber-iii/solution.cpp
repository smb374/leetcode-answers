// Created by Po-Yeh Chen at 2025/01/23 12:17
// leetgo: 1.4.13
// https://leetcode.com/problems/house-robber-iii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
  private:
    unordered_map<TreeNode*, int> robbed;
    unordered_map<TreeNode*, int> skipped;

    pair<int, int> backtrack(TreeNode* node) {
        if (!node)
            return {0, 0};

        pair<int, int> left = backtrack(node->left);
        pair<int, int> right = backtrack(node->right);

        int rob = node->val + left.second + right.second;
        int skip =
            max(left.first, left.second) + max(right.first, right.second);

        return {rob, skip};
    }

  public:
    int rob(TreeNode* root) {
        pair<int, int> res = backtrack(root);

        return max(res.first, res.second);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode* root;
    LeetCodeIO::scan(cin, root);

    Solution* obj = new Solution();
    auto res = obj->rob(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
