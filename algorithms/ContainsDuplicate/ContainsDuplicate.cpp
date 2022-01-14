#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // O(n*logn) - TC, O(1) - SC
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));

        size_t len = nums.size();

        for (int i = 1; i < len; ++i) {
            if (nums[i - 1] == nums[i])
                return true;
        }

        return false;
    }

    // O(n) - TC, O(n) - SC
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;

        for (const auto &n : nums) {
            if (hash_set.count(n) > 0) return true;
            hash_set.insert(n);
        }

        return false;
    }
};