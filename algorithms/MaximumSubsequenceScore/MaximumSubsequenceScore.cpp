#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = int64_t;
public:
  i64 maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    const int n(nums1.size());
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&nums2](int i, int j) -> bool {
      return nums2[i] > nums2[j];
    });

    priority_queue<int, vector<int>, greater<>> pq;
    i64 ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
      cur += nums1[id[i]];
      pq.emplace(nums1[id[i]]);
      if (pq.size() > k) {
        cur -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        ans = max(ans, cur * nums2[id[i]]);
      }
    }
    return ans;
  }
};