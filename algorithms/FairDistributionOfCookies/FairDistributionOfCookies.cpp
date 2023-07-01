#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int distributeCookies(vector<int>& cs, int k) {
    const int n(cs.size());
    vector<vector<int>> cache(1 << n, vector<int>(k + 1, -1));
    auto rec = [&](auto &f, int used, int kk) -> int {
      if (~cache[used][kk]) return cache[used][kk];
      if (kk == 1) {
        int sm = 0;
        for (int i = 0; i < n; ++i) {
          if ((used >> i & 1) == 0) {
            sm += cs[i];
          }
        }
        return sm;
      }
      int ans = 1e9;
      for (int m = 0; m < (1 << n); ++m) {
        if (used & m) continue;
        int sm = 0;
        for (int i = 0; i < n; ++i) {
          if (m >> i & 1) {
            sm += cs[i];
          }
        }
        ans = min(ans, max(sm, f(f, used | m, kk - 1)));
      }
      return cache[used][kk] = ans;
    };
    return rec(rec, 0, k);
  }
};