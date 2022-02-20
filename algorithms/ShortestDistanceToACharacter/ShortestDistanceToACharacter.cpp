#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char ch) {
        const int n = static_cast<int>(s.size());

        vector<int> pref(n), suf(n);

        int lastIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ch) lastIdx = i;
            pref[i] = lastIdx;
        }

        lastIdx = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ch) lastIdx = i;
            suf[i] = lastIdx;
        }

        vector<int> res(n, INT_MAX);

        for (int i = 0; i < n; ++i) {
            if (pref[i] != -1) res[i] = i - pref[i];
            if (suf[i] != -1 and abs(i - pref[i]) > abs(i - suf[i]) or res[i] == INT_MAX) res[i] = suf[i] - i;
        }

        return res;
    }
};