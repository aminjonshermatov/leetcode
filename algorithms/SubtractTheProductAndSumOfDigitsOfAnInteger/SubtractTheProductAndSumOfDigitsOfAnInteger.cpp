#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        auto prod{1};
        auto sum{0};

        while (n > 0) {
            auto cur{n % 10};
            n /= 10;

            prod *= cur;
            sum += cur;
        }

        return prod - sum;
    }
};