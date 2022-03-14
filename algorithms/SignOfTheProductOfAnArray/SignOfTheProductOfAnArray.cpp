#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;

        for (const auto num : nums) {
            if (num == 0) return 0;
            if (num < 0) ++neg;
        }

        return neg & 1 ? -1 : 1;
    }
};