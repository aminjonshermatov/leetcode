#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    ans.reserve(k);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(nums1[0] + nums2[0], 0, 0);
    const int n(nums1.size());
    const int m(nums2.size());
    set<pair<int, int>> used;
    used.emplace(0, 0);
    for (int _ = 0; _ < min<long long>(k, 1ll * n * m); ++_) {
      auto [s, i, j] = pq.top(); pq.pop();
      ans.push_back({nums1[i], nums2[j]});
      if (i + 1 < n && used.count(pair(i + 1, j)) == 0) {
        pq.emplace(nums1[i + 1] + nums2[j], i + 1, j);
        used.emplace(i + 1, j);
      }
      if (j + 1 < m && used.count(pair(i, j + 1)) == 0) {
        pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
        used.emplace(i, j + 1);
      }
    }
    return ans;
  }
};