#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
    vector<vector<int>> ans(2);
    for (auto x : a) {
      if (b.count(x) == 0) {
        ans[0].emplace_back(x);
      }
    }
    for (auto x : b) {
      if (a.count(x) == 0) {
        ans[1].emplace_back(x);
      }
    }
    return ans;
  }
};