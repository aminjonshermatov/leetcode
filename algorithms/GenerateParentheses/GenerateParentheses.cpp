#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string cur;

        backtrack(0, 0, cur, n);

        return res;
    }

    void backtrack(int open, int close, string& cur, int n) {
        if (open + close == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            backtrack(open + 1, close, cur, n);
            cur.pop_back();
        }

        if (open > close && close < n) {
            cur.push_back(')');
            backtrack(open, close + 1, cur, n);
            cur.pop_back();
        }
    }
};