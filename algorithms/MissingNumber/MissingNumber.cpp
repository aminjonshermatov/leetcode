#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t len = nums.size();
        vector<bool> isHere(len + 1);

        for (const auto& n : nums) isHere[n] = true;

        for (size_t i = 0; i <= len; ++i) {
            if (!isHere[i])
                return i;
        }
        return -1;
    }
};
