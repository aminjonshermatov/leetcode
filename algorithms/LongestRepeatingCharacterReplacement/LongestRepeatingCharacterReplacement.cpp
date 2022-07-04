#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n(s.size());

        int f[26] = {0,};
        int ans = k;

        for (int i = 0, j = 0, maxF = 0; j < n; ++j) {
            ++f[s[j] - 'A'];
            maxF = max(maxF, f[s[j] - 'A']);

            if (j - i + 1 - maxF > k) --f[s[i++] - 'A'];

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};