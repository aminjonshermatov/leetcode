#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int numSimilarGroups(vector<string>& strs) {
    const int n(strs.size());
    vector<int> pr(n), rank(n, 1);
    iota(pr.begin(), pr.end(), 0);

    int groups = n;
    auto find_ = [&](auto f, int x) -> int {
      if (pr[x] != x) pr[x] = f(f, pr[x]);
      return pr[x];
    };
    auto union_ = [&](int a, int b) -> void {
      auto pA = find_(find_, a);
      auto pB = find_(find_, b);
      if (pA == pB) return;
      if (rank[pA] < rank[pB]) swap(pA, pB);
      pr[pB] = pA;
      --groups;
      if (rank[pA] == rank[pB]) ++rank[pA];
    };

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (strs[i].size() != strs[j].size()) continue;
        int cnt = 0;
        for (int k = 0; k < strs[i].size(); ++k) {
          cnt += strs[i][k] != strs[j][k];
        }
        if (cnt == 0 || cnt == 2) {
          union_(i, j);
        }
      }
    }
    return groups;
  }
};