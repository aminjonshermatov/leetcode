#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int n = static_cast<int>(strs.size());
        int minEl = INT_MAX;

        for (const auto str : strs) minEl = min(minEl, static_cast<int>(str.size()));

        ostringstream oss;
        bool isOk = true;

        for (int i = 0; i < minEl and isOk; ++i) {
            auto curCh{strs[0][i]};

            for (int j = 1; j < n; ++j) {
                if (curCh != strs[j][i]) {
                    isOk = false;
                    break;
                }
            }

            if (isOk) oss << curCh;
        }

        return oss.str();
    }
};