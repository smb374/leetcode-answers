// Created by Po-Yeh Chen at 2025/01/24 08:50
// leetgo: 1.4.13
// https://leetcode.com/problems/encode-and-decode-strings/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

// @lc code=begin

class Codec {
  public:
    // Encodes a list of strings to a single string.
    string encode(const vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            size_t sz = s.size();
            res += to_string(sz) + "#" + s;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string& s) {
        vector<string> res;
        size_t top = 0, sz = s.size(), base = 0;
        while (top < sz) {
            while (isdigit(s[top])) {
                top++;
            }
            size_t n = stol(std::move(s.substr(base, top - base)));
            top++;
            res.emplace_back(std::move(s.substr(top, n)));
            top += n;
            base = top;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> dummy_input;
    LeetCodeIO::scan(cin, dummy_input);

    Codec* obj = new Codec();
    auto res = obj->encode(dummy_input);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
