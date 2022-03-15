#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums2.size();
        unordered_map<int, int> numToNextGreater;

        for (int i = 0; i < n; ++i) {
            numToNextGreater[nums2[i]] = -1;
            for (int j = i + 1; j < n; ++j) {
                if (nums2[j] > nums2[i]) {
                    numToNextGreater[nums2[i]] = nums2[j];
                    break;
                }
            }
        }

        const int m = nums1.size();
        vector<int> res(m);

        for (int i = 0; i < m; ++i) res[i] = numToNextGreater[nums1[i]];

        return res;
    }
};