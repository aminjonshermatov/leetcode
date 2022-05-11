#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<array<int, 5>> cache(n + 1, {-1, -1, -1, -1, -1});

        function<int(int, int)> dfs = [&](int len, int last) {
            if (len == n) return 1;
            if (cache[len][last] != -1) return cache[len][last];

            int total = 0;
            for (int i = last; i < 5; ++i) {
                total += dfs(len + 1, i);
            }
            return cache[len][last] = total;
        };

        int total = 0;
        for (int i = 0; i < 5; ++i) {
            total += dfs(1, i);
        }

        return total;
    }
};