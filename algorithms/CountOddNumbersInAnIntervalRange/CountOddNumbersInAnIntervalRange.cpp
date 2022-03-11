#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return max(high - low + (high & 1) + (low & 1), 0) >> 1;
    }
};