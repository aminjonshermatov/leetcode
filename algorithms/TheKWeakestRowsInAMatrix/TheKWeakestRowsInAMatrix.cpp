#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int n = static_cast<int>(mat.size());
        vector<pair<int, int>> rows(n);

        for (int i = 0; i < n; ++i) {
            rows[i] = {
                    accumulate(mat[i].begin(), mat[i].end(), 0),
                    i
            };
        }

        sort(rows.begin(), rows.end());

        vector<int> res(k);
        for (int i = 0; i < k; ++i) res[i] = rows[i].second;

        return res;
    }
};