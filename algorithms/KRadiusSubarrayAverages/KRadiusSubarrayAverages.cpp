#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> getAverages(vector<int>& nums, int k) {
    const int n(nums.size());
    vector<int> avg(n, -1);
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
      sm += nums[i];
      if (i > 2 * k) {
        sm -= nums[i - 2 * k - 1];
      }
      if (i >= 2 * k) {
        avg[i - k] = sm / (2 * k + 1);
      }
    }
    return avg;
  }
};