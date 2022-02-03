#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hashMap;

        for (const auto i : nums1) {
            for (const auto j : nums2) {
                ++hashMap[i + j];
            }
        }

        int res = 0;
        for (const auto k : nums3) {
            for (const auto l : nums4) {
                res += hashMap.at(0 - k - l);
            }
        }

        return res;
    }
};