#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = static_cast<int>(nums.size()); i >= 0 and k >= 0; --i, --k) {
            if (k == 0) return nums[i];
        }
        return {};
    }
};