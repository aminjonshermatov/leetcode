#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int n = static_cast<int>(nums.size());

        const function<int(const int)> lowerB = [&](const int k) -> int {
            int lo = 0, hi = n;

            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (nums[mid] >= k) hi = mid;
                else lo = mid + 1;
            }

            return lo;
        };

        for (int i = 1; i <= n; ++i) {
            auto lb{lowerB(i)};
            if (n - lb == i) return i;
        }

        return -1;
    }
};