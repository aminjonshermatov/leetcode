#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    while (num > 9) {
      int sm = 0;
      while (num > 0) {
        auto [q, r] = div(num, 10);
        sm += r;
        num = q;
      }
      num = sm;
    }
    return num;
  }
};