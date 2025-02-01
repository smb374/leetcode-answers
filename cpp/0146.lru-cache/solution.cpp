// Created by Po-Yeh Chen at 2025/01/31 10:45
// leetgo: 1.4.13
// https://leetcode.com/problems/lru-cache/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

struct Node {
    int key, val;
    Node *prev, *next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  private:
    int cap;
    unordered_map<int, Node*> cache;
    vector<Node*> usable;
    Node* last;
    Node* head;

    void remove(Node* node) {
        Node *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node *prev = head->prev, *next = head;
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }

    void update(Node* node) {
        remove(node);
        insert(node);
    }

  public:
    LRUCache(int capacity) : cap(capacity) {
        last = new Node(0, 0);
        head = new Node(0, 0);
        usable.reserve(cap);
        last->next = head;
        head->prev = last;
    }

    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            update(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
            cache[key]->val = value;
            insert(cache[key]);
        } else if (!usable.empty()) {
            Node* node = usable.back();
            usable.pop_back();
            node->key = key;
            node->val = value;
            cache[key] = node;
            insert(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);
        }

        if (cache.size() > cap) {
            Node* lru = last->next;
            remove(lru);
            cache.erase(lru->key);
            usable.push_back(lru);
        }
    }

    // Destructor to release memory used by the nodes
    ~LRUCache() {
        Node* curr = last;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        for (Node* n : usable) {
            delete n;
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    LRUCache* obj;
    const unordered_map<string, function<void()>> methods = {
        {"LRUCache",
         [&]() {
             int capacity;
             LeetCodeIO::scan(cin, capacity);
             cin.ignore();
             obj = new LRUCache(capacity);
             out_stream << "null,";
         }},
        {"get",
         [&]() {
             int key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->get(key));
             out_stream << ',';
         }},
        {"put",
         [&]() {
             int key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             int value;
             LeetCodeIO::scan(cin, value);
             cin.ignore();
             obj->put(key, value);
             out_stream << "null,";
         }},
    };
    cin >> ws;
    out_stream << '[';
    for (auto&& method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
