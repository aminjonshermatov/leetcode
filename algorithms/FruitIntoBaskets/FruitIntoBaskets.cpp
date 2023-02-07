#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& A) {
        const int n(A.size());
        vector<int> cnt(n, 0);
        int cur = 0, ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            if (++cnt[A[r]] == 1) ++cur;
            while (cur > 2) if (--cnt[A[l++]] == 0) --cur;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};