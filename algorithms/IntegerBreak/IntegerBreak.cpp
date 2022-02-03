#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> cache(n + 1, -1);

        const function<int(const int, const int)> dfs = [&](const int curN, const int step) -> int {
            if (curN == 0) return step > 1 ? 1 : -1;
            if (cache[curN] != -1) return cache[curN];

            int res = 1;
            for (int i = 1; i <= curN; ++i) {
                res = max(res, dfs(curN - i, step + 1) * i);
            }

            return cache[curN] = res;
        };

        return dfs(n, 0);
    }
};