#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(n) - TC, O(n) - SC
    void rotate(vector<int>& nums, int k) {
        auto temp{nums};
        int len = nums.size();
        k = k % len;

        if (k == 0) return;

        for (int i = 0; i < len; ++i) {
            int mod_ = (i + k) % len;
            nums[mod_] = temp[i];
        }
    }

    // O(n) - TC, O(1) - SC
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};