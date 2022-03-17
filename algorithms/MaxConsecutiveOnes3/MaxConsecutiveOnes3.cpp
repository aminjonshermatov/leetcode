#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());

        if (count(nums.begin(), nums.end(), 0) <= k) return n;

        auto l{0};
        auto r{0};
        auto zeros{0};

        while (r < n and (zeros < k or nums[r] != 0)) {
            if (nums[r] == 0) ++zeros;
            ++r;
        }
        auto maxL{r};

        for (; r < n; ++r) {
            if (nums[r] == 0) {
                if (nums[l] == 0) ++l;
                else {
                    while (l < r and nums[l] != 0) ++l;
                    ++l;
                }
            }

            maxL = max(maxL, r - l + 1);
        }


        return maxL;
    }
};