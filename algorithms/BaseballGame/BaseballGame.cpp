#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (const string &s : ops) {
            if (s == "+") {
                int b = st.top(); st.pop();
                int a = st.top();
                st.push(b);
                st.push(a + b);
            } else if (s == "D") {
                st.push(2 * st.top());
            } else if (s == "C") {
                st.pop();
            } else st.push(stoi(s));
        }

        int sum{0};
        while (not st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};