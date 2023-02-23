#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    const int n(profits.size());
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);

    sort(ids.begin(), ids.end(), [&](int lhs, int rhs) { return capital[lhs] < capital[rhs]; });
    priority_queue<int> pq;
    for (int i = 0; k > 0;) {
      while (i < n && capital[ids[i]] <= w) pq.push(profits[ids[i++]]);
      if (pq.empty()) break;
      w += pq.top(); pq.pop();
      --k;
    }
    return w;
  }
};