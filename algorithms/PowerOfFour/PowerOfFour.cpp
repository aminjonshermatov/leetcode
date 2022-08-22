#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (__builtin_ctz(n) & 1) == 0;
    }
};