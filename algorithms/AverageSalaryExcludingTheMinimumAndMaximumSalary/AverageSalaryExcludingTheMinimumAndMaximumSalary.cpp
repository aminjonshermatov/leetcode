#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  double average(vector<int>& A) {
    auto [mn, mx] = minmax_element(A.begin(), A.end());
    auto sm = accumulate(A.begin(), A.end(), 0) - *mn - *mx;
    return double(sm) / (static_cast<int>(A.size()) - 2);
  }
};