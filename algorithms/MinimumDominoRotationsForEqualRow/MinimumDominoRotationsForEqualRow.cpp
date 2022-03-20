#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int t[6] = {0};
        int b[6] = {0};
        bool possibles[6];

        const int n = static_cast<int>(tops.size());
        for (int i = 1; i <= n; ++i) {
            ++t[tops[i - 1] - 1];
            ++b[bottoms[i - 1] - 1];

            for (int k = 0; k < 6; ++k) {
                if (i == 1) possibles[k] = true;
                else if (t[k] + b[k] < i or not (tops[i - 1] - 1 == k or bottoms[i - 1] - 1 == k)) possibles[k] = false;
            }
        }

        vector<int> poss;
        for (int k = 0;  k < 6; ++k) {
            if (possibles[k]) poss.push_back(k);
        }

        if (poss.empty()) return -1;

        int res = INT_MAX;
        for (const auto num : poss) {
            res = min(res, min(min(n - t[num], t[num]), min(n - b[num], b[num])));
        }
        return res;
    }
};