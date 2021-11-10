#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int len = nums.size(),
            maj = len / 2,
            lastNum = nums[0],
            count = 1;

        for (int i = 1; i < len; ++i) {
            if (nums[i] == lastNum) ++count;
            else {
                count = 1;
                lastNum = nums[i];
            }

            if (count == maj) return lastNum;
        }

        return -1;
    }
};
