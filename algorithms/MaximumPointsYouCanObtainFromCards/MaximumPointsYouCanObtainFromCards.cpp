#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int n(cardPoints.size());

        vector<int> pf(n + 1, 0);
        for (int i = 1; i <= n; ++i) pf[i] = pf[i - 1] + cardPoints[i - 1];

        // [1,2,3,4]
        //  0 1 2 3 4
        // [0,1,3,6,10]

        int ans = 0;
        for (int i = 0; i <= k; ++i) {
            int f = pf[i];
            int b = pf[n] - pf[n - k + i];
            ans = max(ans, f + b);
        }

        return ans;
    }
};