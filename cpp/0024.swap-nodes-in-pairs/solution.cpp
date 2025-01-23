// Created by Po-Yeh Chen at 2025/01/22 09:40
// leetgo: 1.4.13
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next;

        while (curr && curr->next) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            prev = curr;
            curr = curr->next;
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
    auto res = obj->swapPairs(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
