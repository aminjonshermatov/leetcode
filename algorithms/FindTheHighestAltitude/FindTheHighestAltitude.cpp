#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int ans = 0, cur = 0;
    for (auto x : gain) {
      ans = max(ans, cur += x);
    }
    return ans;
  }
};