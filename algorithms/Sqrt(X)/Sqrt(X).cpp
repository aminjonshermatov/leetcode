#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = 46341; // magic number is math.ceil(math.sqrt(INT_MAX))

        while (lo + 1 < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (mid * mid <= x) lo = mid;
            else hi = mid;
        }

        return x == 1 ? 1 : lo;
    }
};