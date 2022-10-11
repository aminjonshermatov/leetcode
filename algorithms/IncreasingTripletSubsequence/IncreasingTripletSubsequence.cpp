#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a, b;
        a = b = numeric_limits<int>::max();
        for (auto num : nums) {
            if (num < a) a = num;
            else if (num < b && num > a) b = num;
            else if (num > b) return true;
        }

        return false;
    }
};