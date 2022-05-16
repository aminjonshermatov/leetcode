#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int n(nums.size());

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            // cout << lo << ' ' << mid << ' ' << hi << '\n';
            if (mid & 1) {
                if (mid > 0) {
                    if (nums[mid - 1] == nums[mid]) lo = mid + 1;
                    else hi = mid;
                } else return nums.front();
            } else {
                if (mid + 1 < n) {
                    if (nums[mid + 1] == nums[mid]) lo = mid + 1;
                    else hi = mid;
                } else return nums.back();
            }
        }

        // cout << lo << ' ' << hi << '\n';
        return nums[lo];
    }
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (const auto num : nums) ans ^= num;
        return ans;
    }
};