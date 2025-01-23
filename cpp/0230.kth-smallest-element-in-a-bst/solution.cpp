// Created by Po-Yeh Chen at 2025/01/21 09:01
// leetgo: 1.4.13
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  private:
    TreeNode* inorder_walk(TreeNode* node, int& pos, const int& k) {
        if (!node)
            return node;

        TreeNode* left = inorder_walk(node->left, pos, k);
        if (left)
            return left;

        if (++pos == k)
            return node;

        return inorder_walk(node->right, pos, k);
    }

  public:
    int kthSmallest(TreeNode* root, int k) {
        int pos = 0;
        TreeNode* node = inorder_walk(root, pos, k);

        return node ? node->val : -1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode* root;
    LeetCodeIO::scan(cin, root);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->kthSmallest(root, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
