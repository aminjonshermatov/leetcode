#include "bits/stdc++.h"

using namespace std;

class Solution {
  static constexpr auto inf = numeric_limits<int>::max();
  struct SegmentTree {
    int n;
    vector<pair<int, int>> tree;
    pair<int, int> neutral = pair(inf, -1);
    explicit SegmentTree(vector<int> &nums) {
      n = 1;
      while (n < nums.size()) n <<= 1;
      tree.assign(2 * n - 1, neutral);
      auto build = [&](auto &f, int x, int lx, int rx) -> void {
        if (rx - lx == 1) {
          if (lx < nums.size()) {
            tree[x] = pair(nums[lx], lx);
          }
          return;
        }
        auto mid = lx + (rx - lx) / 2;
        f(f, 2 * x + 1, lx, mid);
        f(f, 2 * x + 2, mid, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
      };
      build(build, 0, 0, n);
    }
    pair<int, int> qry(int ql, int qr, int x, int lx, int rx) {
      if (ql >= rx || qr <= lx) return neutral;
      if (ql <= lx && rx <= qr) return tree[x];
      auto mid = lx + (rx - lx) / 2;
      return min(qry(ql, qr, 2 * x + 1, lx, mid), qry(ql, qr, 2 * x + 2, mid, rx));
    }
    pair<int, int> qry(int ql, int qr) {
      return qry(ql, qr, 0, 0, n);
    }
    void upd(int pos, int val, int x, int lx, int rx) {
      if (rx - lx == 1) {
        tree[x] = pair(val, lx);
        return;
      }
      auto mid = lx + (rx - lx) / 2;
      if (pos < mid) {
        upd(pos, val, 2 * x + 1, lx, mid);
      } else {
        upd(pos, val, 2 * x + 2, mid, rx);
      }
      tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void upd(int pos, int val) {
      upd(pos, val, 0, 0, n);
    }
  };
public:
  using i64 = long long;
  i64 totalCost(vector<int>& cs, int k, int cand) {
    const int n(cs.size());
    SegmentTree sg(cs);
    i64 ans = 0;
    int ro = 0, lo = 0;
    while (k--) {
      auto [mn, pos] = min(sg.qry(0, min(n, cand + lo)), sg.qry(max(0, n - cand - ro), n));
      ans += mn;
      if (clamp(pos, 0, min(n, cand + lo) - 1) == pos) ++lo;
      else if (clamp(pos, max(0, n - cand - ro), n - 1) == pos) ++ro;
      else assert(false);
      sg.upd(pos, inf);
    }
    return ans;
  }
};