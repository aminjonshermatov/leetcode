#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        function<int(int)> count = [&](int t) {
            int res = 0;
            for (const auto num : nums) res += (num + t - 1) / t - 1;
            return res;
        };

        int lo = 1, hi = 1e9 + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (count(mid) <= maxOperations) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};