#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0, score = 0;

        const int n(tokens.size());
        sort(tokens.begin(), tokens.end());
        for (int lo = 0, hi = n - 1; lo <= hi && (power >= tokens[lo] || score > 0);) {
            while (lo <= hi && power >= tokens[lo]) {
                ++score;
                power -= tokens[lo++];
            }

            ans = max(ans, score);
            if (lo <= hi && score > 0) {
                --score;
                power += tokens[hi--];
            }
        }

        return ans;
    }
};