#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int n = static_cast<int>(nums.size());

        int i = 0, j = 0;
        while (i < n and nums[i] != val) ++i;
        j = i + 1;

        while (i < n) {
            while (j < n and nums[j] == val) ++j;

            if (j != n) nums[i++] = nums[j++];
            else break;
        }

        return i;
    }
};