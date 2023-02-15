#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> res;
    const int n(num.size());
    for (int i = n - 1, rem = 0; i >= 0 || k > 0 || rem > 0; --i, k /= 10) {
      int cur = rem;
      if (i >= 0) cur += num[i];
      if (k > 0) cur += k % 10;
      res.push_back(cur % 10);
      rem = cur / 10;
    }
    reverse(res.begin(), res.end());

    return res;
  }
};