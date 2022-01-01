#include "bits/stdc++.h"

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    using ll = long long;
    int firstBadVersion(int n) {
        ll l = -1, r = n;

        while (l + 1 < r) {
            ll mid = l + (r - l) / 2;

            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return static_cast<int>(r);
    }
};