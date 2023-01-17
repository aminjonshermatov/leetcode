#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int n(s.size());
        vector<int> z(n + 2, 0), o(n + 2, 0);
        for (int i = 1; i <= n; ++i) z[i] = z[i - 1] + (s[i - 1] != '0');
        for (int i = n; i > 0; --i) o[i] = o[i + 1] + (s[i - 1] != '1');

        auto ans = numeric_limits<int>::max();
        for (int i = 0; i <= n; ++i) ans = min(ans, z[i] + o[i + 1]);
        return ans;
    }
};