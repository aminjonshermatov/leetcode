#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;

        for (int i = 0; i < 31; ++i) {
            int mask = 1 << i;

            if ((left & mask) and (right & mask) and (right - left < mask)) res |= mask;
        }

        return res;
    }
};