#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int, 3> counts;

        for (const auto n : nums) ++counts[n];

        int idx = 0;

        for (int i = 0; i < 3; ++i) {
            while (counts[i]--) nums[idx++] = i;
        }
    }
};