#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;

        function<void(int)> backtrack = [&](int idx) -> void {
            int len = cur.size();

            if (len == k) {
                res.emplace_back(cur);
                return;
            }

            for (int i = idx; i < n; ++i) {
                cur.push_back(i + 1);
                backtrack(i + 1);
                cur.pop_back();
            }
        };

        backtrack(0);

        return res;
    }
};