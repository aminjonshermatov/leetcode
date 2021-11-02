#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>&& nums) {
        unordered_set<int> uniq;

        for (const auto& n : nums) uniq.insert(n);

        size_t len = nums.size();
        vector<int> missing;
        for (int i = 1; i <= len; ++i) {
            if (uniq.count(i) == 0) {
                missing.push_back(i);
            }
        }

        return missing;
    }
};