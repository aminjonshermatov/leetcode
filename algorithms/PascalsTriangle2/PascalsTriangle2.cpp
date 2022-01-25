#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> cache;

    inline auto c(int n, int k) -> int {
        if (n == 0 or k == 0 or n == k) return 1;
        if (k > n) return 0;
        if (cache[n][k] != -1) return cache[n][k];

        return cache[n][k] = c(n - 1, k - 1) + c(n - 1, k);
    }

    auto getRow(int rowIndex) -> vector<int> {
        cache.resize(rowIndex + 1, vector<int>(rowIndex + 1, -1));

        vector<int> res(rowIndex + 1, 1);

        for (int i = 1; i <= ((rowIndex >> 1) + (rowIndex & 1)); ++i) {
            res[i] = res[rowIndex - i] = c(rowIndex, i);
        }

        return res;
    }
};