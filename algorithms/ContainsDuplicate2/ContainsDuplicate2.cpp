#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int N(nums.size());
        map<int, vector<int>> mm;

        for (int i = 0; i < N; ++i) {
            mm[nums[i]].push_back(i);
        }

        for (auto &[_, v] : mm) {
            for (int i = 1; i < (int)v.size(); ++i) {
                if (v[i] - v[i - 1] <= k) return true;
            }
        }

        return false;
    }
};