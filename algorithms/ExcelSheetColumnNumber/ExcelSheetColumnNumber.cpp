#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;

        for (const auto ch : columnTitle) res = res * 26 + (ch - 'A' + 1);

        return res;
    }

    int titleToNumber(string columnTitle) {
        return accumulate(columnTitle.begin(), columnTitle.end(), 0, [](const auto acc, const auto cur) { return acc * 26 + (cur - 'A' + 1); });
    }
};