#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        auto g = __gcd(p, q);
        p /= g;
        q /= g;

        if (q & 1) {
            if (p & 1) return 1;
            else return 2;
        } else {
            if (p & 1) return 0;
            else return 3;
        }
    }
};