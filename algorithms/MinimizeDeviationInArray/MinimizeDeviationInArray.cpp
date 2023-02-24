#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    multiset<int> ms;
    for (auto x : nums) ms.insert(x);

    auto upd = [&]() -> int { return *prev(ms.end()) - *ms.begin(); };
    int ans = upd();
    while (*ms.begin() & 1) {
      auto x = ms.begin();
      ms.insert(*x * 2);
      ms.erase(x);
      ans = min(ans, upd());
    }

    while (*prev(ms.end()) % 2 == 0) {
      auto x = prev(ms.end());
      ms.insert(*x / 2);
      ms.erase(x);
      ans = min(ans, upd());
    }

    while (*ms.begin() & 1) {
      auto x = ms.begin();
      ms.insert(*x * 2);
      ms.erase(x);
      ans = min(ans, upd());
    }

    return ans;
  }
};