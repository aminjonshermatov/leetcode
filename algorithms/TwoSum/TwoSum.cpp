#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n(nums.size());

        unordered_map<int, int> hmap;
        for (int i = 0; i < n; ++i) {
            if (hmap.count(target - nums[i]) != 0) return {i, hmap.at(target - nums[i])};
            hmap[nums[i]] = i;
        }

        return {};
    }
};