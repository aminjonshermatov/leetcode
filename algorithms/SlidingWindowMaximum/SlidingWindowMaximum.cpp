#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n(nums.size());

        vector<int> res;
        res.reserve(n - k + 1);

        multiset<int> ms;
        for (int l = 0, r = 0; r < n; ++r) {
            ms.insert(nums[r]);

            if (r - l + 1 > k) {
                auto it = ms.find(nums[l++]);
                ms.erase(it);
            }

            if (r - l + 1 == k) res.push_back(*ms.rbegin());
        }

        return res;
    }
};
