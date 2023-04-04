#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int partitionString(string s) {
    int ans = 0;
    array<int, 26> cnt{};
    auto zero = [&]() -> void { fill(cnt.begin(), cnt.end(), 0); };
    zero();
    for (auto c : s) {
      if (cnt[c - 'a'] > 0) ++ans, zero();
      ++cnt[c - 'a'];
    }
    return ++ans;
  }
};