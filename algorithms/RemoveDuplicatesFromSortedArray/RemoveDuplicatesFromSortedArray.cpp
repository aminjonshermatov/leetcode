#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N(nums.size());

        int i = 0;
        for (int j = 0; j < N; ++i, ++j) {
            nums[i] = nums[j];
            while (j + 1 < N && nums[j + 1] == nums[i]) ++j;
        }
        return i;
    }
};