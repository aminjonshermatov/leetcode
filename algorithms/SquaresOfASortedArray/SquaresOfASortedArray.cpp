#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        vector<int> res(len);

        if (nums[0] >= 0) {
            for (int i = 0; i < len; ++i) res[i] = nums[i] * nums[i];
        } else if (nums[len - 1] < 0) {
            for (int i = 0; i < len; ++i) res[i] = nums[len - i - 1] * nums[len - i - 1];
        } else {
            int i = 0;
            while (nums[i] < 0) ++i;

            int pos = i, neg = i - 1;
            i = 0;

            while (i < len) {
                if (pos == len || neg >= 0 && -nums[neg] < nums[pos]) {
                    res[i] = nums[neg] * nums[neg];
                    --neg;
                } else {
                    res[i] = nums[pos] * nums[pos];
                    ++pos;
                }

                ++i;
            }
        }

        return res;
    }
};