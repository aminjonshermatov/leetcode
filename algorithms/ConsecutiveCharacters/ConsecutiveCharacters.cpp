#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        auto maxL{0};

        auto curL{0};
        char prev = '1';

        for (const auto ch : s) {
            if (prev != ch) curL = 0;
            prev = ch;
            ++curL;

            maxL = max(maxL, curL);
        }

        return maxL;
    }
};