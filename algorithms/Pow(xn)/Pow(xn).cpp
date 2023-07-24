#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double res = 1;
    auto is_neg = n < 0;
    n = abs(n);
    for (; n > 0; n >>= 1, x *= x) {
      if (n & 1) {
        if (is_neg) {
          res /= x;
        } else {
          res *= x;
        }
      }
    }
    return res;
  }
};