#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        return num ^ (static_cast<long long>(1 << bitLen(num)) - 1);
    }

    inline int bitLen(int num) {
        int count = 0;

        while (num > 0) {
            ++count;
            num >>= 1;
        }

        return count;
    }
};