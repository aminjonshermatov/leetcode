#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int k = n;

        for (int i = 0; i < k; ++i) {
            int j = i + 1;
            while (j < k and nums[i] == nums[j]) ++j;

            if (i + 1 == j) continue;
            k -= j - i - 1;

            int ii = i + 1;
            while (j < n and ii < n) nums[ii++] = nums[j++];
        }

        return k;
    }
};