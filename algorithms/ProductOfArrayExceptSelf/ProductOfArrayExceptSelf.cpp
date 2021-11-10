#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        vector<int> ans(len, 1);

        int prefix = 1,
                postfix = 1;

        for (int i = 0; i < len; ++i) {
            ans[i] *= prefix;
            prefix *= nums[i];
            ans[len - i - 1] *= postfix;
            postfix *= nums[len - i - 1];
        }

        return ans;
    }
};