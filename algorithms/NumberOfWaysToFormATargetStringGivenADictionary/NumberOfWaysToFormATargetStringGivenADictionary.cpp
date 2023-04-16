#include "bits/stdc++.h"

using namespace std;

class Solution {
  using ll = long long;
  static inline constexpr auto mod = int(1e9 + 7);
public:
  int numWays(vector<string>& words, string target) {
    const int n(words[0].size());
    const int m(target.size());

    vector<array<int, 26>> cnt(n);
    for (auto &x : cnt) {
      fill(x.begin(), x.end(), 0);
    }

    for (int i = 0; i < n; ++i) {
      for (const auto &w : words) {
        ++cnt[i][w[i] - 'a'];
      }
    }

    vector<vector<ll>> cache(n, vector<ll>(m, -1));
    auto dp = [&](auto f, int i, int j) -> ll {
      if (j == m) return 1;
      if (i >= n) return 0;
      if (~cache[i][j]) return cache[i][j];

      ll ans = 0;
      for (int k = i; m - j <= n - k; ++k) {
        if (cnt[k][target[j] - 'a'] > 0) {
          ans += cnt[k][target[j] - 'a'] * f(f, k + 1, j + 1);
          ans %= mod;
        }
      }
      return cache[i][j] = ans;
    };
    return dp(dp, 0, 0);
  }
};