#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0],
                h = nums[0];

        do {
            t = nums[t];
            h = nums[nums[h]];
        } while (t != h);

        t = nums[0];
        while (t != h) {
            t = nums[t];
            h = nums[h];
        }

        return t;
    }

    int findDuplicate(vector<int>& nums) {
        for (const auto num : nums) {
            if (nums[abs(num) - 1] < 0) return abs(num);
            nums[abs(num) - 1] *= -1;
        }

        return {};
    }
};