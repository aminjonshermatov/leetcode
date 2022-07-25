
#include "bits/stdc++.h"

using namespace std;

class Solution {
    int n;
    vector<string> res;
    string cur;

    void backtrack(int open, int closed) {
        if (open + closed == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (open + 1 <= n) {
            cur.push_back('(');
            backtrack(open + 1, closed);
            cur.pop_back();
        }

        if (closed + 1 <= open && open + 1 + closed <= 2 * n) {
            cur.push_back(')');
            backtrack(open, closed + 1);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n_) {
        n = n_;
        cur.reserve(2 * n);

        backtrack(0, 0);
        return res;
    }
};