#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> cnt{};
        cnt[0] = 1;
        for (auto cur = 0; auto num : nums) {
            cur += num;
            auto rem = ((cur % k) + k) % k;
            ans += cnt[rem];
            ++cnt[rem];
        }

        return ans;
    }
};