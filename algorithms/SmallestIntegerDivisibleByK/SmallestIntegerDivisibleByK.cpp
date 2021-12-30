#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if ((k & 1) == 0) return -1;

        int rem = 1, len = 1;

        unordered_set<int> hashSet;

        while (rem % k != 0) {
            ++len;
            rem = (rem * 10 + 1LL) % k;

            if (hashSet.count(rem) > 0) return -1;
            hashSet.insert(rem);
        }

        return len;
    }
};