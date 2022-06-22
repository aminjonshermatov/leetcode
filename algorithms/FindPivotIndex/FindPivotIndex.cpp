#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n(nums.size());

        vector<int> sf(n, 0);
        sf[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) sf[i] = sf[i + 1] + nums[i + 1];

        int pf = 0;
        for (int i = 0; i <= n - 1; ++i) {
            if (pf == sf[i]) return i;
            pf += nums[i];
        }

        return -1;
    }
};