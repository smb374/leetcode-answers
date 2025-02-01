// Created by Po-Yeh Chen at 2025/01/30 09:23
// leetgo: 1.4.13
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;

        ListNode dummy(-1, head);
        ListNode *slow = &dummy, *fast = &dummy, *prev;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = slow->next;
        return dummy.next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution* obj = new Solution();
    auto res = obj->removeNthFromEnd(head, n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
