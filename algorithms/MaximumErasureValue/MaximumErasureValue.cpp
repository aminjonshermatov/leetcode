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

class Solution {
    static constexpr inline size_t SZ = 1e4 + 1;
    bool seen[SZ];
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        memset(seen, 0, sizeof(seen));
        int ans = 0, sum = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (l < r && seen[nums[r]]) {
                sum -= nums[l];
                seen[nums[l++]] = false;
            }

            sum += nums[r];
            ans = max(ans, sum);
            seen[nums[r]] = true;
        }

        return ans;
    }
};