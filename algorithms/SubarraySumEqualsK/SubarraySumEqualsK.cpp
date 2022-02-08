#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        int res = 0;

        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            if (hashMap.count(sum - k) > 0) res += hashMap.at(sum - k);
            ++hashMap[sum];
        }

        return res;
    }
};