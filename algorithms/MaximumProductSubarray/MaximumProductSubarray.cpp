#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minv = 1,
            maxv = 1,
            ans = INT_MIN;

        for (const int& n : nums) {
            int _minv = min(n, min(minv * n, maxv * n));
            int _maxv = max(n, max(minv * n, maxv * n));
            minv = _minv;
            maxv = _maxv;

            ans = max(ans, maxv);
        }

        return ans;
    }
};