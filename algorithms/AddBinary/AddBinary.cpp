#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    const int n(a.size());
    const int m(b.size());
    string c;
    int rem = 0;
    for (int i = 0, j = 0; i < n || j < m; ++i, ++j) {
      int cur = rem;
      if (i < n) cur += a[i] - '0';
      if (j < m) cur += b[j] - '0';
      c.push_back('0' + cur % 2);
      rem = cur / 2;
    }
    while (rem) {
      c.push_back('0' + rem % 2);
      rem /= 2;
    }
    reverse(c.begin(), c.end());
    return c;
  }
};