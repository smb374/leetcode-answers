// Created by Po-Yeh Chen at 2025/01/18 15:50
// leetgo: 1.4.13
// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next;
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }

        while (count >= k) {
            curr = prev->next;
            next = curr->next;

            for (int i = 1; i < k; i++) {
                // p -> c -> n -> L
                // p -> (c, n) -> L
                // (p, n) -> c -> L
                // p -> n -> c -> L
                // p -> c' -> n' -> L'
                // where L = n' -> L'
                //       c' = n -> c
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;
            count -= k;
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution* obj = new Solution();
    auto res = obj->reverseKGroup(head, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
