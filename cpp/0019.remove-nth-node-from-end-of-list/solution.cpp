// Created by Po-Yeh Chen at 2025/01/15 12:19
// leetgo: 1.4.13
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
        ListNode dummy(-1, head);
        int count = 0;
        for (ListNode* curr = head; curr; curr = curr->next) {
            count++;
        }
        int target = count - n;
        ListNode *prev = &dummy, *curr = head;

        for (int i = 0; i < target && curr->next; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

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
