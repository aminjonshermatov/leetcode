#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap_1, hashMap_2;

        for (const auto n : nums1) ++hashMap_1[n];
        for (const auto n : nums2) ++hashMap_2[n];

        vector<int> res;

        for (auto [k, v] : hashMap_1) {
            if (v > 0 and hashMap_2.count(k) > 0) {
                int sz = min(v, hashMap_2[k]);

                while (sz--) res.push_back(k);

                hashMap_1[k] = hashMap_2[k] = 0;
            }
        }

        return res;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        const int n = static_cast<int>(nums1.size());
        const int m = static_cast<int>(nums2.size());

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;

        int i = 0, j = 0;
        while (i < n and j < m) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i++]);
                ++j;
                continue;
            }

            if (nums1[i] < nums2[j]) ++i;
            else ++j;
        }

        return res;
    }
};