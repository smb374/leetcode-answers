// Created by Po-Yeh Chen at 2025/01/18 10:49
// leetgo: 1.4.13
// https://leetcode.com/problems/linked-list-cycle/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
            return false;

        ListNode *slow = head->next, *fast = head->next->next;
        while (fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow == fast;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);
    int pos;
    LeetCodeIO::scan(cin, pos);

    Solution* obj = new Solution();
    auto res = obj->hasCycle(head, pos);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
