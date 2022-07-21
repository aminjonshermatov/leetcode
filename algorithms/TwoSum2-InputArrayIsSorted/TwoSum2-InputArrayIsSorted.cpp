#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < numbers.size(); ++i) {
            if (hash.count(target - numbers[i]) > 0) return {hash[target - numbers[i]], i + 1};
            hash[numbers[i]] = i + 1;
        }

        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        for (int l = 0, r = static_cast<int>(nums.size()) - 1; l < r;) {
            int cur = nums[l] + nums[r] - target;

            if (cur < 0) ++l;
            else if (cur > 0) --r;
            else return {l + 1, r + 1};
        }

        return {};
    }
};
