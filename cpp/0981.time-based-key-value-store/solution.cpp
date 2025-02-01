// Created by Po-Yeh Chen at 2025/01/29 09:47
// leetgo: 1.4.13
// https://leetcode.com/problems/time-based-key-value-store/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class TimeMap {
  private:
    unordered_map<string, vector<pair<int, string>>> data;

  public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (!data.count(key))
            return "";
        auto& vec = data[key];
        int lo = 0, hi = vec.size();

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (vec[mid].first == timestamp) {
                return vec[mid].second;
            } else if (vec[mid].first < timestamp) {
                lo = mid + 1;
            } else if (vec[mid].first > timestamp) {
                hi = mid;
            }
        }

        return hi > 0 ? vec[hi - 1].second : "";
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    TimeMap* obj;
    const unordered_map<string, function<void()>> methods = {
        {"TimeMap",
         [&]() {
             cin.ignore();
             obj = new TimeMap();
             out_stream << "null,";
         }},
        {"set",
         [&]() {
             string key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             string value;
             LeetCodeIO::scan(cin, value);
             cin.ignore();
             int timestamp;
             LeetCodeIO::scan(cin, timestamp);
             cin.ignore();
             obj->set(key, value, timestamp);
             out_stream << "null,";
         }},
        {"get",
         [&]() {
             string key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             int timestamp;
             LeetCodeIO::scan(cin, timestamp);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->get(key, timestamp));
             out_stream << ',';
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
