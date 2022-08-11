#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        const int N(nums.size());

        int ans = 0;
        for (size_t i = 0; i < N - 2; ++i) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + diff);
            if (j == nums.end() || *j != nums[i] + diff) continue;
            auto k = lower_bound(next(j), nums.end(), *j + diff);
            if (k == nums.end() || *k != *j + diff) continue;
            ++ans;
        }

        return ans;
    }
};