#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int>& P, int limit) {
    const int n(P.size());
    sort(P.begin(), P.end());
    int ans = 0;
    for (int l = 0, r = n - 1; l <= r; ++ans, --r) {
      if (P[l] + P[r] <= limit) ++l;
    }
    return ans;
  }
};