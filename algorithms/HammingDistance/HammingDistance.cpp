#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(log(x + y)) - TC, O(1) - SC
    int hammingDistance(int x, int y) {
        int hamDis = 0;

        while (x != 0 || y != 0) {
            hamDis += (x & 1) ^ (y & 1);

            x >>= 1;
            y >>= 1;
        }

        return hamDis;
    }
};