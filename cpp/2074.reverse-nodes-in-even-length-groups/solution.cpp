// Created by Po-Yeh Chen at 2025/01/23 09:31
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
        int limit = 1;

        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head, *next;

        while (prev->next) {
            curr = prev->next;
            int count = 1;
            for (int i = 0; i < limit - 1 && curr->next; i++) {
                count++;
                curr = curr->next;
            }
            if (count % 2 == 0) {
                curr = prev->next;
                next = curr->next;

                for (int i = 0; i < count - 1; i++) {
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
