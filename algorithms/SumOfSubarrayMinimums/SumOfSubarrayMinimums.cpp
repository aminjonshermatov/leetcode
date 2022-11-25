#include "bits/stdc++.h"

using namespace std;

class Solution {
    using ll = long long;
    static inline constexpr ll MOD = ll(1e9 + 7);
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int n(arr.size());

        vector<int> l2r(n, n), r2l(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                l2r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                r2l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ll(i - r2l[i]) * (l2r[i] - i) * arr[i];
            ans %= MOD;
        }

        return ans;
    }
};