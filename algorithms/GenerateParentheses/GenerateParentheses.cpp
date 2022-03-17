#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        list<char> cur;

        const function<void(const int, const int)> generate = [&](const int open, const int close) -> void {
            if (open + close == 2 * n) {
                res.emplace_back(cur.begin(), cur.end());
                return;
            }

            if (open < n) {
                cur.push_back('(');
                generate(open + 1, close);
                cur.pop_back();
            }

            if (close < open) {
                cur.push_back(')');
                generate(open, close + 1);
                cur.pop_back();
            }
        };

        generate(0, 0);

        return res;
    }
};