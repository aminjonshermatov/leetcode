#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        int curSum = 0;

        backtrack(0, cur, curSum, target, candidates);

        return res;
    }

    void backtrack(int idx, vector<int>& cur, int& curSum, int target, vector<int>& cand) {
        for (int i = idx; i < cand.size(); ++i) {
            if (curSum + cand[i] > target) {
                return;
            }
            else {
                cur.push_back(cand[i]);
                curSum += cand[i];

                if (curSum == target) res.push_back(cur);
                else backtrack(i, cur, curSum, target, cand);

                cur.pop_back();
                curSum -= cand[i];
            }
        }
    }
};