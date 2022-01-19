#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positive = 0,
            negative = 0,
            ans = 0;

        for (const auto n : nums) {
            if (n == 0) {
                positive = 0;
                negative = 0;
            } else if (n > 0) {
                ++positive;
                negative = negative == 0 ? 0 : negative + 1;
            } else {
                auto temp{positive};
                positive = negative == 0 ? 0 : negative + 1;
                negative = temp + 1;
            }

            ans = max(ans, positive);
        }

        return ans;
    }
};