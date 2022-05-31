#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int cur = 0;
        set<int> uniq;

        const int kk = 1 << k;
        const int n(s.size());
        for (int i = 0, j = 0; j < n; ++j) {
            cur <<= 1;
            if (j - i >= k) {
                cur &= kk - 1;
                ++i;
            }
            cur |= s[j] == '1' ? 1 : 0;
            if (j - i + 1 == k) uniq.insert(cur);
        }

        return uniq.size() == kk;
    }
};