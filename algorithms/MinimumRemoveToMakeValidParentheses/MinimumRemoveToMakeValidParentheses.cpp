#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int close = 0, open = 0;

        for (const auto ch : s) {
            if (ch == '(') {
                ++open;
                st.push(ch);
            } else if (ch == ')') {
                if (open > close) {
                    ++close;
                    st.push(ch);
                }
            } else st.push(ch);
        }

        list<char> res;
        while (not st.empty()) {
            auto ch = st.top(); st.pop();

            if (ch == '(' and open > close) --open;
            else res.push_front(ch);
        }

        return {res.begin(), res.end()};
    }
};