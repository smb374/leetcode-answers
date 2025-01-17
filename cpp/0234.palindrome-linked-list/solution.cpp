// Created by Po-Yeh Chen at 2025/01/17 09:11
// leetgo: 1.4.13
// https://leetcode.com/problems/palindrome-linked-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        if (!head->next->next)
            return head->val == head->next->val;
        // 1. Fast and slow to find list middle.
        ListNode *slow = head->next, *fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2. Reverse second half of the list.
        ListNode *prev = slow, *curr = slow->next;
        prev->next = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // 3. Check palindrome.
        fast = head;
        slow = prev;
        while (slow) {
            if (slow->val != fast->val) {
                return false;
            }
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
