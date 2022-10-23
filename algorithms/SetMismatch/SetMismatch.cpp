#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N(nums.size());
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        set<int> seen;

        for (auto num : nums) {
            if (seen.count(num) > 0) return {num, N*(N+1)/2 - sum + num};
            seen.insert(num);
        }

        return {};
    }
};