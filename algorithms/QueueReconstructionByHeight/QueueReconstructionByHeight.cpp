#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &lhs, auto &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] > rhs[0];
        });

        const int n(people.size());
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            res.insert(res.begin() + people[i][1], people[i]);
        }

        return res;
    }
};