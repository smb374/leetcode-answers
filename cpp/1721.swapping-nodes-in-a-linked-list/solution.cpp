// Created by Po-Yeh Chen at 2025/01/18 18:06
// leetgo: 1.4.13
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        ListNode dummy(-1, head);
        ListNode *fast = &dummy, *slow = &dummy, *prev, *p1, *p2;
        for (int i = 0; i < k; i++) {
            prev = fast;
            fast = fast->next;
        }
        p1 = prev;
        int j = 0;
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            j++;
        }
        p2 = prev;

        if (j == k)
            return dummy.next;
        else if (j < k)
            swap(p1, p2);

        ListNode *c1 = p1->next, *c2 = p2->next;
        ListNode *n1 = c1->next, *n2 = c2->next;

        if (c1->next == c2) {
            p1->next = c2;
            c2->next = c1;
            c1->next = n2;
        } else {
            p1->next = c2;
            c2->next = n1;
            p2->next = c1;
            c1->next = n2;
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
    auto res = obj->swapNodes(head, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
