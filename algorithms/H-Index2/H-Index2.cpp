#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        stack<int> st;

        const int n = (int)c.size();
        for (int i = n - 1; ~i; --i) {
            if (st.empty() || c[i] >= st.size() + 1) st.push(c[i]);
        }



        return st.empty()
               ? 0
               : st.size() == 1
                 ? min(1, st.top())
                 : st.size();
    }
};