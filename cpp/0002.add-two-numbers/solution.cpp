// Created by Po-Yeh Chen at 2025/01/31 09:18
// leetgo: 1.4.13
// https://leetcode.com/problems/add-two-numbers/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode dummy(-1);
        ListNode *p1 = l1, *p2 = l2, *prev = &dummy;
        int carry = 0;
        while (p1 && p2) {
            int val = p1->val + p2->val + carry;
            prev->next = new ListNode(val % 10);
            carry = val / 10;
            prev = prev->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            int val = p1->val + carry;
            prev->next = new ListNode(val % 10);
            carry = val / 10;
            prev = prev->next;
            p1 = p1->next;
        }
        while (p2) {
            int val = p2->val + carry;
            prev->next = new ListNode(val % 10);
            carry = val / 10;
            prev = prev->next;
            p2 = p2->next;
        }
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }

        return dummy.next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* l1;
    LeetCodeIO::scan(cin, l1);
    ListNode* l2;
    LeetCodeIO::scan(cin, l2);

    Solution* obj = new Solution();
    auto res = obj->addTwoNumbers(l1, l2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
