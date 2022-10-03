#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lo = 0, hi = static_cast<int>(nums.size()) - 1;

        while (lo < hi) {
            if ((nums[hi] & 1) == 0) {
                swap(nums[lo++], nums[hi]);
            } else --hi;
        }

        return nums;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        const auto mx = *max_element(nums.begin(), nums.end());

        vector<int> fr(mx + 1, 0);
        for (const auto num : nums) ++fr[num];

        const int N(nums.size());
        vector<int> res;
        res.reserve(N);

        for (auto s : {0, 1})
            for (int i = s; i < mx + 1; i += 2)
                if (fr[i] > 0) for (int j = 0; j < fr[i]; ++j) res.emplace_back(i);

        return res;
    }
};