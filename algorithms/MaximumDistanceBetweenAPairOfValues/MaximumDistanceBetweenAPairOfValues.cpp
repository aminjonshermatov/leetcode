#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int n = static_cast<int>(nums1.size());
        const int m = static_cast<int>(nums2.size());

        const function<int(const int)> upperB = [&](const int target) {
            int lo = 0, hi = m;

            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (nums2[mid] < target) hi= mid;
                else lo = mid + 1;
            }

            return lo;
        };

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int j = upperB(nums1[i]) - 1;

            if (i <= j and nums1[i] <= nums2[j]) res = max(res, j - i);
        }

        return res;
    }
};