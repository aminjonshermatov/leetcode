#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    const int n(word1.size());
    const int m(word2.size());
    string res(n + m, '#');
    for (int k = 0, i = 0, j = 0; k < n + m; ++k) {
      if (i < n && j < m) {
        res[k] = k & 1 ? word2[j++] : word1[i++];
      } else if (i < n) {
        res[k] = word1[i++];
      } else if (j < m) {
        res[k] = word2[j++];
      } else {
        assert(false);
      }
    }

    return res;
  }
};