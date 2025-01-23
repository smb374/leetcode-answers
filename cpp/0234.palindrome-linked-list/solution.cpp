// Created by Po-Yeh Chen at 2025/01/21 08:12
// leetgo: 1.4.13
// https://leetcode.com/problems/palindrome-linked-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=begin

class Solution {
  private:
    ListNode* reverse(ListNode* head) {
        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next = head->next;

        while (next) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        return dummy.next;
    }

  public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode *slow = head->next, *fast = head->next->next, *prev = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* back = reverse(slow);
        slow = head;
        fast = back;

        while (slow) {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution* obj = new Solution();
    auto res = obj->isPalindrome(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
