#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;

        backtrack(res, cur, 0, k, n);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& cur, int idx, int k, int n) {
        int len = cur.size();

        if (len == k) {
            res.push_back(cur);
            return;
        }

        for (int i = idx; i < n; ++i) {
            cur.push_back(i + 1);
            backtrack(res, cur, i + 1, k, n);
            cur.pop_back();
        }
    }
};