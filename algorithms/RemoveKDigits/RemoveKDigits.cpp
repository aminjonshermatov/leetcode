#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        const int n = static_cast<int>(num.size());

        if (k == n) return "0";

        stack<char> st;

        for (const auto ch : num) {
            while (not st.empty() and (ch < st.top() or ch == '0') and k > 0) {
                st.pop();
                --k;
            }

            if (not (ch == '0' and st.empty())) st.push(ch);
        }

        while (not st.empty() and k--) st.pop();

        string res;

        while (not st.empty()) {
            res.insert(res.begin(), st.top());
            st.pop();
        }

        return res.empty() ? "0" : res;
    }
};