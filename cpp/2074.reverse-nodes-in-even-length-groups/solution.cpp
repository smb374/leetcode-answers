// Created by Po-Yeh Chen at 2025/01/18 18:39
// leetgo: 1.4.13
// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int limit = 1, i, len = 0;
        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next;
        while (curr) {
            len++;
            curr = curr->next;
        }
        curr = head;
        while (len) {
            curr = prev->next;
            next = curr->next;
            if (limit % 2 == 0) {
                for (int i = 1; i < limit; i++) {
                    curr->next = next->next;
                    next->next = prev->next;
                    prev->next = next;
                    next = curr->next;
                }
            } else {
                for (int i = 1; i < limit; i++) {
                    curr = curr->next;
                }
            }
            len -= limit;
            limit = min(len, limit + 1);
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
