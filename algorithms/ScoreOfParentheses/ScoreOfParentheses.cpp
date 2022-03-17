#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (const auto ch : s) {
            if (ch == '(') st.push(0);
            else {
                auto cur{st.top()}; st.pop();
                auto prev{st.top()}; st.pop();

                st.push(prev + max(1, 2 * cur));
            }
        }

        return st.top();
    }
};