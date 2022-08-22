#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        for (int l = 0, r = 0, w = 0; r < blocks.size(); ++r) {
            if (r - l + 1 > k) w -= blocks[l++] == 'W';
            w += blocks[r] == 'W';
            if (r - l + 1 == k) ans = min(ans, w);
        }

        return ans;
    }
};