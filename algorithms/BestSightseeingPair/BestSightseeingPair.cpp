#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> maxL(n);
        int maxEl = maxL[0] = values[0];

        for (int i = 1; i < n; ++i) {
            maxEl = max(maxEl, values[i] + i);
            maxL[i] = maxEl;
        }

        int maxR = values[n - 1] - n + 1,
            ans = maxL[n - 2] + maxR;

        for (int i = n - 2; i > 0; --i) {
            maxR = max(maxR, values[i] - i);
            ans = max(ans, maxL[i - 1] + maxR);
        }

        return ans;
    }
};