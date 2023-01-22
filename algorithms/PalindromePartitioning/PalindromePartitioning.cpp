#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n(s.size());

        auto ok = [&](int i, int j) -> bool {
            for (; i < j; ++i, --j) if (s[i] != s[j]) return false;
            return true;
        };

        vector<vector<string>> res;
        vector<string> cur;
        auto rec = [&](auto f, int i) -> void {
            if (i >= n) {
                res.emplace_back(cur);
                return;
            }

            for (int j = i; j < n; ++j) {
                if (ok(i, j)) {
                    cur.emplace_back(s.substr(i, j - i + 1));
                    f(f, j + 1);
                    cur.pop_back();
                }
            }
        };
        rec(rec, 0);

        return res;
    }
};