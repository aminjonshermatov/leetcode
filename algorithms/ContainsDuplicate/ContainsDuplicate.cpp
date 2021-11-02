#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));

        size_t len = nums.size();

        for (int i = 1; i < len; ++i) {
            if (nums[i - 1] == nums[i])
                return true;
        }

        return false;
    }
};