#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& as) {
    stack<int> st;
    for (auto a : as) {
      bool need_ins = true;
      while (!st.empty() && a < 0 && st.top() > 0) {
        if (abs(a) > abs(st.top())) {
          st.pop();
          need_ins = true;
        } else if (abs(a) < abs(st.top())) {
          need_ins = false;
          break;
        } else {
          st.pop();
          need_ins = false;
          break;
        }
      }
      if (need_ins) {
        st.push(a);
      }
    }
    vector<int> ans;
    while (!st.empty()) {
      ans.emplace_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};