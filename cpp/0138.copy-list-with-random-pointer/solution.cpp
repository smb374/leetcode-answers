// Created by Po-Yeh Chen at 2025/01/30 09:31
// leetgo: 1.4.13
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=begin

class Solution {
  public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        unordered_map<Node*, Node*> node_table;
        node_table[nullptr] = nullptr;

        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            node_table[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* copy = node_table[curr];
            copy->next = node_table[curr->next];
            copy->random = node_table[curr->random];
            curr = curr->next;
        }

        return node_table[head];
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    Node* head;
    LeetCodeIO::scan(cin, head);

    Solution* obj = new Solution();
    auto res = obj->copyRandomList(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
