#include "bits/stdc++.h"

using namespace std;

class Solution {
  map<char, char> opp = {{')', '('}, {'}', '{'}, {']', '['}};
public:
  bool isValid(string s) {
    stack<char> st;

    for (auto ch : s) {
      if (opp.count(ch) > 0) {
        if (st.empty() || st.top() != opp[ch]) return false;
        st.pop();
      } else {
        st.push(ch);
      }
    }
    return st.empty();
  }
};