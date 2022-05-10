#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        list<int> cur;

        const function<void(int, int)> backtrack = [&](int n_, int k_) {
            if (k_ == k) {
                if (n_ == 0) res.emplace_back(cur.begin(), cur.end());
                return;
            }

            for (int i = (cur.empty() ? 1 : cur.back() + 1); i <= 9; ++i) {
                if (n_ - i < 0) break;

                cur.push_back(i);
                backtrack(n_ - i, k_ + 1);
                cur.pop_back();
            }
        };

        backtrack(n, 0);

        return res;
    }
};