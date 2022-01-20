#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            int hoursSpent = 0;

            for (const auto n : piles) {
                hoursSpent += n / mid + static_cast<int>(n % mid != 0);
            }

            if (hoursSpent <= h) hi = mid;
            else lo = mid + 1;
        }

        return hi;
    }
};