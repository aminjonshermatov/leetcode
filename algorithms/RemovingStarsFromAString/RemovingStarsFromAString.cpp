#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (auto ch : s) {
            if (ch == '*') st.pop();
            else st.push(ch);
        }

        string ans;
        ans.resize(st.size());
        for (int i = (int)st.size() - 1; i >= 0; --i) ans[i] = st.top(), st.pop();

        return ans;
    }
};