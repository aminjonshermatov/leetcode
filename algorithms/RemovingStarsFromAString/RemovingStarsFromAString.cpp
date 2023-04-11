#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  string removeStars(string s) {
    stack<char> st;
    for (auto ch : s) {
      if (ch == '*') {
        assert(!st.empty());
        st.pop();
      } else {
        st.push(ch);
      }
    }
    string res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};