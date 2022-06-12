#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, sum = 0;
        unordered_set<int> ss;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (l < r && ss.count(nums[r]) > 0) {
                auto it = ss.find(nums[l]);
                sum -= nums[l++];
                ss.erase(it);
            }

            sum += nums[r];
            ans = max(ans, sum);
            ss.insert(nums[r]);
        }

        return ans;
    }
};