#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        char prevCh;
        int maxPower = -1, counter = 0;

        for (const auto& ch : s) {
            if (ch == prevCh) ++counter;
            else {
                prevCh = ch;
                counter = 1;
            }
            maxPower = max(maxPower, counter);
        }

        return maxPower;
    }
};