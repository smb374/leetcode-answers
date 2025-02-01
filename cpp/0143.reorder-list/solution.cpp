// Created by Po-Yeh Chen at 2025/01/30 09:10
// leetgo: 1.4.13
// https://leetcode.com/problems/reorder-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=begin

class Solution {
  public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode front(-1), back(-1);
        ListNode *slow = head->next, *fast = head->next->next, *curr, *prev;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = &front;
        curr = head;
        while (curr != slow) {
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        prev = &back;
        curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }

        ListNode *p1 = front.next, *p2 = back.next;

        while (true) {
            ListNode *n1 = p1->next, *n2 = p2->next;
            p1->next = p2;
            if (n1) {
                p2->next = n1;
                p1 = n1;
                p2 = n2;
            } else {
                break;
            }
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution* obj = new Solution();
    obj->reorderList(head);
    LeetCodeIO::print(out_stream, head);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
