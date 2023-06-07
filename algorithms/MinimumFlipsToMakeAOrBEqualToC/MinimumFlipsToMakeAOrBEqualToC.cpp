#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ans = 0;
    for (int i = 0; i < 30; ++i) {
      auto cc = c >> i & 1;
      auto ca = a >> i & 1;
      auto cb = b >> i & 1;
      if (cc == 0) {
        ans += ca + cb;
      } else {
        ans += (ca + cb) == 0;
      }
    }
    return ans;
  }
};