#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    set<char> vow{'a', 'e', 'i', 'o', 'u'};

    int cnt = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i >= k) {
        cnt -= vow.count(s[i - k]) > 0;
      }
      cnt += vow.count(s[i]) > 0;
      ans = max(ans, cnt);
    }
    return ans;
  }
};