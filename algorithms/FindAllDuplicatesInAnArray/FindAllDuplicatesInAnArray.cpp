#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        for (int& num : nums) {
            int n = abs(num) - 1;

            if (nums[n] < 0) {
                res.emplace_back(abs(num));
            } else {
                nums[n] *= -1;
            }
        }

        return res;
    }
};