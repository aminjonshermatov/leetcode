#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long double res = 1.0;
        auto nn = static_cast<long long>(n);

        if (nn != 0 && x != 1) {
            bool isNeg = false;

            if (n < 0) {
                isNeg = true;
                nn *= -1;
            }

            while (nn) {
                if (nn & 1) {
                    if (isNeg) res /= x;
                    else res *= x;
                }

                x *= x;
                nn >>= 1;
            }
        }

        return res;
    }
};