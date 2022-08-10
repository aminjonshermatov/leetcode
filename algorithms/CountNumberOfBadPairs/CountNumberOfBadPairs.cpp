#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const int N(nums.size());
        map<int, long long> freq;

        long long res = 0;
        for (int i = 0; i < N; ++i) {
            res += i - freq[i - nums[i]];
            ++freq[i - nums[i]];
        }

        return res;
    }
};