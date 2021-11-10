#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.count(target - nums[i]) > 0) {
                return {hashMap[target - nums[i]], i};
            }

            hashMap.insert({nums[i], i});
        }

        return {};
    }
};
