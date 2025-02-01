// Created by Po-Yeh Chen at 2025/01/23 08:38
// leetgo: 1.4.13
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string digits;
	LeetCodeIO::scan(cin, digits);

	Solution *obj = new Solution();
	auto res = obj->letterCombinations(digits);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
