#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1, hi = 46341; // magic number -> math.ceil(sqrt(INT_MAX))

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            auto sqr{mid * mid};
            if (sqr < num) lo = mid + 1;
            else if (sqr > num) hi = mid;
            else return true;
        }

        return false;
    }
};