#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    const int n = static_cast<int>(nums.size());

    int minL = INT_MAX, l = 0, r = 0, window = 0;

    while (r < n) {
      window += nums[r];

      while (window >= target) {
        minL = min(minL, r - l + 1);
        window -= nums[l++];
      }

      ++r;
    }

    return minL == INT_MAX ? 0 : minL;
  }
};

class Solution {
  struct SegmentTree {
    int n;
    vector<pair<int, int>> tree;
    pair<int, int> neutral =
        pair(numeric_limits<int>::max(), numeric_limits<int>::max());
    explicit SegmentTree(int n_) {
      n = 1;
      while (n < n_)
        n <<= 1;
      tree.assign(2 * n - 1, neutral);
    }
    void set(int pos, int val, int x, int lx, int rx) {
      if (rx - lx == 1) {
        tree[x] = pair(val, lx);
        return;
      }
      auto mid = lx + (rx - lx) / 2;
      if (pos < mid) {
        set(pos, val, 2 * x + 1, lx, mid);
      } else {
        set(pos, val, 2 * x + 2, mid, rx);
      }
      tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int pos, int val) { return set(pos, val, 0, 0, n); }
    int qry(int pos, int val, int x, int lx, int rx) {
      if (tree[x].second >= pos || tree[x].first > val)
        return -1;
      if (rx - lx == 1)
        return lx;
      auto mid = lx + (rx - lx) / 2;
      auto id = qry(pos, val, 2 * x + 2, mid, rx);
      if (id == -1) {
        id = qry(pos, val, 2 * x + 1, lx, mid);
      }
      return id;
    }
    int qry(int pos, int val) { return qry(pos, val, 0, 0, n); }
  };

public:
  int minSubArrayLen(int target, vector<int> &nums) {
    const int n(nums.size());
    SegmentTree sg(n + 1);
    const auto inf = numeric_limits<int>::max();
    int sm = 0, ans = inf;
    sg.set(0, 0);
    for (int i = 0; i < n; ++i) {
      sm += nums[i];
      sg.set(i + 1, sm);
      auto id = sg.qry(i + 1, sm - target);
      if (id != -1) {
        ans = min(ans, i - id + 1);
      }
    }
    return ans == inf ? 0 : ans;
  }
};