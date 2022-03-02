#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = static_cast<int>(s.size());
        const int m = static_cast<int>(t.size());

        if (n != 0 and m == 0) return false;

        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m and t[j] != s[i]) ++j;

            if (j == m) return false;
            ++j;
        }

        return true;
    }
};