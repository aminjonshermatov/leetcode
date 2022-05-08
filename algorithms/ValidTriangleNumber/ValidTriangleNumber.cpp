#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());

        int res = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int lo = j + 1, hi = n;

                while (lo < hi) {
                    int mid = lo + ((hi - lo) >> 1);

                    if (nums[mid] >= nums[i] + nums[j]) hi = mid;
                    else lo = mid + 1;
                }

                res += lo - j - 1;
            }
        }

        return res;
    }
};