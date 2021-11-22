#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        int curSum = 0;

        backtrack(1, res, cur, curSum, k, n);

        return res;
    }

    void backtrack(int idx, vector<vector<int>>& res, vector<int>& cur, int curSum, int k, int n) {
        if (cur.size() == k) {
            if (curSum == n) res.push_back(cur);

            return;
        }

        for (int i = idx; i <= n && i <= 9; ++i) {
            if (curSum + i > n) return;

            cur.push_back(i);
            curSum += i;

            backtrack(i + 1, res, cur, curSum, k, n);

            cur.pop_back();
            curSum -= i;
        }
    }
};