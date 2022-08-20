#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniq;
        for (auto num : nums) if (num != 0) uniq.insert(num);
        return uniq.size();
    }
};