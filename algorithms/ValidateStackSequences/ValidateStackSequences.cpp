#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    const int n(pushed.size()), m(popped.size());
    stack<int> st;
    int i = 0;
    for (auto x : pushed) {
      if (i >= m) return false;
      if (x == popped[i]) {
        ++i;
        while (!st.empty() && i < m && st.top() == popped[i]) {
          ++i;
          st.pop();
        }
      }
      else st.push(x);
    }

    while (!st.empty() && i < m && st.top() == popped[i]) {
      ++i;
      st.pop();
    }

    return st.empty() && i == m;
  }
};