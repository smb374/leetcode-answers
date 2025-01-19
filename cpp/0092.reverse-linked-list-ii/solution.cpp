// Created by Po-Yeh Chen at 2025/01/18 16:02
// leetgo: 1.4.13
// https://leetcode.com/problems/reverse-linked-list-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next;
        int i;
        for (i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        next = curr->next;
        for (i = left; i < right; i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        return dummy.next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);
    int left;
    LeetCodeIO::scan(cin, left);
    int right;
    LeetCodeIO::scan(cin, right);

    Solution* obj = new Solution();
    auto res = obj->reverseBetween(head, left, right);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
