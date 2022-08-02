#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        const auto n = mat.size();

        if (k == 1 || k == n * n) return mat[(k - 1) / n][(k - 1) % n];

        int lo = mat[0][0], hi = mat[n - 1][n - 1];
        for (; lo < hi;) {
            int c = 0, mid = lo + ((hi - lo) >> 1);

            for (size_t i = 0; i < n; ++i) {
                auto& row = mat[i];
                c += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }

            if (c < k) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};