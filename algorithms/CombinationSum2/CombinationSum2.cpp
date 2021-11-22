#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        int curSum = 0;

        backtrack(res, 0, cur, curSum, candidates, target);

        return res;
    }

    void backtrack(vector<vector<int>>& res, int idx, vector<int>& cur, int curSum, vector<int>& cand, int target) {
        for (int i = idx; i < cand.size(); ++i) {
            if (curSum + cand[i] > target) break;
            else {

                cur.push_back(cand[i]);
                curSum += cand[i];

                if (curSum == target) res.push_back(cur);
                else backtrack(res, i + 1, cur, curSum, cand, target);

                curSum -= cand[i];
                cur.pop_back();
            }

            while (i + 1 < cand.size() && cand[i] == cand[i + 1]) ++i;
        }
    }
};