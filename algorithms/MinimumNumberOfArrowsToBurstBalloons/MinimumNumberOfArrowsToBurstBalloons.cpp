#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& A) {
        const int n(A.size());
        sort(A.begin(), A.end(), [&](auto &lhs, auto &rhs) -> bool {
            return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
        });

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int end = A[i][1];
            while (i + 1 < n && A[i + 1][0] <= end) {
                if (A[i + 1][0] <= end) end = min(end, A[++i][1]);
            }
            ++ans;
        }
        return ans;
    }
};