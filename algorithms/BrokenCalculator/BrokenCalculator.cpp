#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        auto step{0};

        while (startValue < target) {
            ++step;

            if (target & 1) ++target;
            else target >>= 1;
        }

        return step + startValue - target;
    }
};