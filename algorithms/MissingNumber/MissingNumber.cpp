#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        return (n * (n + 1) >> 1) - accumulate(nums.begin(), nums.end(), 0);
    }
};