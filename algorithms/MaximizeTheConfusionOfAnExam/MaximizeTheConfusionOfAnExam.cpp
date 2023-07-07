#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxConsecutiveAnswers(string as, int k) {
    const int n(as.size());
    int ans = 0;
    for (auto ch : {'T', 'F'}) {
      for (int i = 0, l = 0, xs = 0; i < n; ++i) {
        xs += as[i] == ch;
        while (l <= i && xs > k) {
          xs -= as[l++] == ch;
        }
        ans = max(ans, i - l + 1);
      }
    }
    return ans;
  }
};