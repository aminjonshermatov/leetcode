#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        const int n(s1.size());
        const int m(s2.size());

        for (int k = min(n, m); k > 0; --k) {
            if (n % k != 0 || m % k != 0) continue;
            bool ok = true;
            for (int i = 0; i < n; ++i) ok &= s1[i] == s1[i % k];
            for (int i = 0; i < m; ++i) ok &= s2[i] == s2[i % k];
            for (int i = 0; i < k; ++i) ok &= s1[i] == s2[i];
            if (ok) return s1.substr(0, k);
        }
        return {};
    }
};