// Created by Po-Yeh Chen at 2025/02/01 10:14
// leetgo: 1.4.13
// https://leetcode.com/problems/same-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q)
            return p == q;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right && p->val == q->val;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode* p;
    LeetCodeIO::scan(cin, p);
    TreeNode* q;
    LeetCodeIO::scan(cin, q);

    Solution* obj = new Solution();
    auto res = obj->isSameTree(p, q);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
