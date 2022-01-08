#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](const auto &acc, const auto &n) -> int { return acc ^ n; });
    }
};