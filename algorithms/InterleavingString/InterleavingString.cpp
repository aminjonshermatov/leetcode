#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    const int n(s1.size());
    const int m(s2.size());
    const int k(s3.size());
    if (n + m != k) return false;
    vector<vector<vector<int>>> cache(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    auto dp = [&](auto f, int i, int j, int z) -> bool {
      if (z >= n + m) return true;
      if (~cache[i][j][z]) return cache[i][j][z];
      return cache[i][j][z]
             = (i < n && s1[i] == s3[z] && f(f, i + 1, j, z + 1)) || (j < m && s2[j] == s3[z] && f(f, i, j + 1, z + 1));
    };

    return dp(dp, 0, 0, 0);
  }
};