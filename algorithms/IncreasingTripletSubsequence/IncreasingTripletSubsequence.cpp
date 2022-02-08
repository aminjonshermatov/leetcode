#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        if (n < 3) return false;

        int a = INT_MAX, b = INT_MAX;

        for (const auto num : nums) {
            if (num < a) {
                a = num;
            } else if (num < b and num > a) {
                b = num;
            } else if (num > b) {
                return true;
            }
        }

        return false;
    }
};