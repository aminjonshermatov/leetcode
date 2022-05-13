#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        function<bool(int)> canEat = [&](int k) {
            int h_ = 0;
            for (const auto n : piles) h_ += (n + k - 1) / k;
            return h_ <= h;
        };

        int lo = 1, hi = 1e9 + 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (canEat(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};