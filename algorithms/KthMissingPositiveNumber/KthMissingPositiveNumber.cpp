#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int n = static_cast<int>(arr.size());

        const function<bool(const int)> bSearch = [&](const int target) -> bool {
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (arr[mid] < target) lo = mid + 1;
                else if (arr[mid] > target) hi = mid;
                else return true;
            }

            return false;
        };

        for (int i = 1, j = 0; j <= k; ++i) {
            if (not bSearch(i)) {
                ++j;

                if (j == k) return i;
            }
        }

        return {};
    }
};