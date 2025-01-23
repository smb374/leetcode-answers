// Created by Po-Yeh Chen at 2025/01/22 09:24
// leetgo: 1.4.13
// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next;
        int limit = 1, size;

        while (prev->next) {
            curr = prev->next;
            for (size = 1; size < limit && curr->next; size++) {
                curr = curr->next;
            }
            if (size % 2 == 0) {
                curr = prev->next;
                next = curr->next;
                for (int i = 0; i < size - 1; i++) {
                    curr->next = next->next;
                    next->next = prev->next;
                    prev->next = next;
                    next = curr->next;
                }
            }
            limit++;
            prev = curr;
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

    Solution* obj = new Solution();
    auto res = obj->reverseEvenLengthGroups(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
