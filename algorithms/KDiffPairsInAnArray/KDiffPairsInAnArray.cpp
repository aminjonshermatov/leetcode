#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = static_cast<int>(nums.size());

        unordered_set<int> h_set;
        unordered_set<int> used;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            const int num = nums[i];

            if (h_set.count(num - k) > 0) ++res;
            else if (h_set.count(num + k) > 0) ++res;

            h_set.insert(num);

            while (i + 1 < n and nums[i + 1] == num) {
                ++i;
                if (k == 0 and used.count(num) == 0) {
                    used.insert(num);
                    ++res;
                }
            }
        }

        return res;
    }
};