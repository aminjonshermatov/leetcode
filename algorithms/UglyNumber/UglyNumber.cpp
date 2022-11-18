#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        for (auto k : {2, 3, 5}) while (n % k == 0) n /= k;
        return n == 1;
    }
};