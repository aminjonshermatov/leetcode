#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>&& prices) {
        int maxProf = 0;

        size_t len = prices.size();
        for (size_t i = 0; i < len; ++i) {
            if (i + 1 == len) break;

            if (prices[i] < prices[i + 1]) {
                size_t j = i + 1;

                while (j < len && prices[j] > prices[i]) {
                    maxProf = max(maxProf, prices[j++] - prices[i]);
                }
            }
        }

        return maxProf;
    }

    int maxProfit(vector<int>& prices) {
        const int n(prices.size());
        stack<int> st;

        for (int i = n - 1; i > 0; --i) {
		st.push(st.empty() ? prices[i] : max(st.top(), prices[i]));
        }

        int ans = 0;
        for (int i = 0; !st.empty(); ++i, st.pop()) {
            ans = max(ans, st.top() - prices[i]);
        }

        return ans;
    }
};
