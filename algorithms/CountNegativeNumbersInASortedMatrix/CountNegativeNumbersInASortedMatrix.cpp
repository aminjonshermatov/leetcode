#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int lo = 0, hi = m;

            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (grid[i][mid] >= 0) lo = mid + 1;
                else hi = mid;
            }

            count += m - lo;
        }

        return count;
    }
};