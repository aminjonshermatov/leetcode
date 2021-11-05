#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (mid * (mid + 1) <= 2 * n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return --l;
    }
};