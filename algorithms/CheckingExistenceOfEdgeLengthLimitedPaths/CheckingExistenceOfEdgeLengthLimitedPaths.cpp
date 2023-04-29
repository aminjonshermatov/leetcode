#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    const int m(edgeList.size());
    const int q(queries.size());
    sort(edgeList.begin(), edgeList.end(), [](const auto &lhs, const auto &rhs) {
      return lhs[2] < rhs[2];
    });
    vector<int> qs(q);
    iota(qs.begin(), qs.end(), 0);
    sort(qs.begin(), qs.end(), [&](int i, int j) {
      return queries[i][2] < queries[j][2];
    });

    vector<int> pr(n), rank(n, 1);
    iota(pr.begin(), pr.end(), 0);

    auto find_ = [&](auto f, int v) -> int {
      if (pr[v] != v) pr[v] = f(f, pr[v]);
      return pr[v];
    };
    auto union_ = [&](int v, int u) -> void {
      int pV = find_(find_, v);
      int pU = find_(find_, u);
      if (pV == pU) return;
      if (rank[pV] < rank[pU]) swap(pV, pU);
      pr[pU] = pV;
      if (rank[pV] == rank[pU]) ++rank[pV];
    };

    int i = 0;
    vector<bool> ans(q);
    for (auto &qi : qs) {
      while (i < m && edgeList[i][2] < queries[qi][2]) {
        union_(edgeList[i][0], edgeList[i][1]);
        ++i;
      }
      ans[qi] = find_(find_, queries[qi][0]) == find_(find_, queries[qi][1]);
    }
    return ans;
  }
};