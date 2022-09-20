#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        const int N(nums1.size());
        const int M(nums2.size());

        vector<vector<int>> dp(N, vector<int>(M, 0));

        int ans = 0;
        for (int i = 0; i < N; ++i) if (nums1[i] == nums2[M - 1]) dp[i][N - 1] = 1, ans = 1;
        for (int j = 0; j < M; ++j) if (nums1[N - 1] == nums2[j]) dp[N - 1][j] = 1, ans = 1;

        for (int i = N - 2; i >= 0; --i) {
            for (int j = M - 2; j >= 0; --j) {
                if (nums1[i] == nums2[j]) dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]), ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};