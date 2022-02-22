#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;

        for (const auto ch : columnTitle) res = res * 26 + (ch - 'A' + 1);

        return res;
    }
};