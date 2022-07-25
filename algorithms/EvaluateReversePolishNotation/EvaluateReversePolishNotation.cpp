#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const auto &s : tokens) {
            if (isdigit(s.back())) {
                st.push(stoi(s));
            } else {
                assert(st.size() > 1);
                auto y = st.top(); st.pop();
                auto x = st.top(); st.pop();

                if (s == "+") st.push(x + y);
                else if (s == "-") st.push(x - y);
                else if (s == "*") st.push(x * y);
                else if (s == "/") st.push(x / y);
            }
        }

        assert(st.size() == 1);
        return st.top();
    }
};