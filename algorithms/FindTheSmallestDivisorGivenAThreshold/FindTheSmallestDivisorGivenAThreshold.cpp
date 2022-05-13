#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        function<int(int)> count = [&](int d) {
            int res = 0;
            for (const auto num : nums) res += (num + d - 1) / d;

            return res;
        };

        int lo = 1, hi = 1e6 + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (count(mid) > threshold) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};