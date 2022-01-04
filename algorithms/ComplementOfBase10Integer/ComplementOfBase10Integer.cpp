#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        return ((2 << bitCount(n)) - 1) ^ n;
    }

    inline int bitCount(int n) {
        int count = 0;

        while (n > 0) {
            ++count;
            n >>= 1;
        }

        return count > 0 ? count - 1 : 0;
    }
};