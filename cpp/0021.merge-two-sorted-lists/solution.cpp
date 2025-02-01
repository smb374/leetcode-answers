// Created by Po-Yeh Chen at 2025/01/30 08:53
// leetgo: 1.4.13
// https://leetcode.com/problems/merge-two-sorted-lists/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode dummy(-1);
        ListNode *prev = &dummy, *p1 = list1, *p2 = list2;

        while (p1 && p2) {
            if (p1->val < p2->val) {
                prev->next = p1;
                p1 = p1->next;
            } else {
                prev->next = p2;
                p2 = p2->next;
            }
            prev = prev->next;
        }

        if (p1)
            prev->next = p1;
        else if (p2)
            prev->next = p2;

        return dummy.next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* list1;
    LeetCodeIO::scan(cin, list1);
    ListNode* list2;
    LeetCodeIO::scan(cin, list2);

    Solution* obj = new Solution();
    auto res = obj->mergeTwoLists(list1, list2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
