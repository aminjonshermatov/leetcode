#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> vals;

        auto sum{0};
        auto pre{0};
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            auto mod{sum % k};

            if (vals.count(mod) > 0) return true;
            vals.insert(pre);
            pre = mod;
        }

        return false;
    }
};