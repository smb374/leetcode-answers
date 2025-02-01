// Created by Po-Yeh Chen at 2025/01/31 10:34
// leetgo: 1.4.13
// https://leetcode.com/problems/merge-k-sorted-lists/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(
            cmp);
        ListNode dummy(-1);
        ListNode* prev = &dummy;

        for (auto h : lists) {
            if (h) {
                min_heap.push(h);
            }
        }

        while (!min_heap.empty()) {
            ListNode* top = min_heap.top();
            min_heap.pop();
            prev->next = top;
            prev = prev->next;
            if (top->next) {
                min_heap.push(top->next);
            }
        }

        return dummy.next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<ListNode*> lists;
    LeetCodeIO::scan(cin, lists);

    Solution* obj = new Solution();
    auto res = obj->mergeKLists(lists);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
