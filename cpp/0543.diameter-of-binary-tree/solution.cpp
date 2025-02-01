// Created by Po-Yeh Chen at 2025/02/01 09:52
// leetgo: 1.4.13
// https://leetcode.com/problems/diameter-of-binary-tree/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
    int helper(TreeNode* node, int& diameter) {
        if (!node)
            return 0;

        int left = helper(node->left, diameter);
        int right = helper(node->right, diameter);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

  public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode* root;
    LeetCodeIO::scan(cin, root);

    Solution* obj = new Solution();
    auto res = obj->diameterOfBinaryTree(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
