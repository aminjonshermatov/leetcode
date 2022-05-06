#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (const auto c : s) {
            if (st.empty() || st.top().first != c) st.push({c, 1});
            else if (st.top().first == c) {
                if (st.top().second == k - 1) st.pop();
                else ++st.top().second;
            }
        }

        string res;
        while (!st.empty()) {
            int rem = st.top().second % k;

            if (rem != 0) res.insert(res.end(), st.top().second, st.top().first);
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};