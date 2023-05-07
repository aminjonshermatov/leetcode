#include "bits/stdc++.h"

using namespace std;

class Solution {
  static constexpr auto ninf = numeric_limits<int>::min();

  struct SegmentTree {
    int len;
    vector<int> tree;

    explicit SegmentTree(int n) {
      len = 1;
      while (len < n) len <<= 1;
      tree.assign(2 * len - 1, ninf);
    }

    void set(int pos, int val, int x, int lx, int rx) {
      if (rx - lx == 1) {
        tree[x] = max(val, tree[x]);
        return;
      }
      auto mid = lx + (rx - lx) / 2;
      if (pos < mid) set(pos, val, 2 * x + 1, lx, mid);
      else set(pos, val, 2 * x + 2, mid, rx);
      tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int pos, int val) {
      set(pos, val, 0, 0, len);
    }

    int get(int ql, int qr, int x, int lx, int rx) {
      if (ql >= rx || qr <= lx) return ninf;
      if (ql <= lx && rx <= qr) return tree[x];
      auto mid = lx + (rx - lx) / 2;
      return max(get(ql, qr, 2 * x + 1, lx, mid), get(ql, qr, 2 * x + 2, mid, rx));
    }

    int get(int ql, int qr) { // till pos, i.e [0..i]
      auto mx = get(ql, qr, 0, 0, len);
      return mx == ninf ? 0 : mx;
    }
  };
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
    const int n(A.size());
    auto B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    const int nn(B.size());
    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
      id[i] = int(lower_bound(B.begin(), B.end(), A[i]) - B.begin());
    }

    SegmentTree st(nn);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = st.get(0, id[i] + 1) + 1;
      st.set(id[i], ans[i]);
    }
    return ans;
  }
};