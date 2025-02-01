// Created by Po-Yeh Chen at 2025/02/01 09:56
// leetgo: 1.4.13
// https://leetcode.com/problems/balanced-binary-tree/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
  private:
    pair<int, bool> helper(TreeNode* node) {
        if (!node)
            return {0, true};

        auto [left, left_ok] = helper(node->left);
        auto [right, right_ok] = helper(node->right);

        return {1 + max(left, right),
                left_ok && right_ok && abs(left - right) <= 1};
    }

  public:
    bool isBalanced(TreeNode* root) { return helper(root).second; }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode* root;
    LeetCodeIO::scan(cin, root);

    Solution* obj = new Solution();
    auto res = obj->isBalanced(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
