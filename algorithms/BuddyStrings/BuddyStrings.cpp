#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool buddyStrings(string a, string b) {
    if (a.size() != b.size()) return false;
    const int n(a.size());
    if (a == b && set<char>(a.begin(), a.end()).size() < n) return true;
    vector<int> dif;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        dif.emplace_back(i);
      }
    }
    return dif.size() == 2 && a[dif[0]] == b[dif[1]] && a[dif[1]] == b[dif[0]];
  }
};