#include "bits/stdc++.h"

using namespace std;

class Solution {
  using i64 = int64_t;
public:
  int maxValue(int n, int index, int maxSum) {
    auto sum = [&](i64 a1, i64 nn, i64 d) -> i64 {
      return (2 * a1 + d * (nn - 1)) * nn / 2;
    };
    i64 lo = 0, hi = maxSum + 1;
    while (hi - lo > 1) {
      auto mid = lo + (hi - lo) / 2;
      auto lhs = sum(mid - 1, min<i64>(index, mid - 1), -1) + max<i64>(0, index - mid + 1);
      auto rhs = sum(mid - 1, min<i64>(n - index - 1, mid - 1), -1) + max<i64>(0, n - index - mid);
      (lhs + mid + rhs <= maxSum ? lo : hi) = mid;
    }
    return lo;
  }
};