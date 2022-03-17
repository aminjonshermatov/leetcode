#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const auto &str : tokens) {
            if (str == "/") {
                auto last{st.top()}; st.pop();
                auto preLast{st.top()}; st.pop();

                st.push(preLast / last);
            } else if (str == "*") {
                auto last{st.top()}; st.pop();
                auto preLast{st.top()}; st.pop();

                st.push(preLast * last);
            } else if (str == "-") {
                auto last{st.top()}; st.pop();
                auto preLast{st.top()}; st.pop();

                st.push(preLast - last);
            } else if (str == "+") {
                auto last{st.top()}; st.pop();
                auto preLast{st.top()}; st.pop();

                st.push(preLast + last);
            } else st.push(stoi(str));
        }

        return st.top();
    }
};