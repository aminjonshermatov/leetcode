#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
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
};