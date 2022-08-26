#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string dig;

        for (; n > 0; n /= 10) dig.push_back('0' + n % 10);
        reverse(dig.begin(), dig.end());
        string cur;

        function<bool(int, bool)> perm = [&](int mask, bool anyNonZ = false) {
            if (cur.size() == dig.size()) {
                int num = 0;
                for (auto ch : cur) num = num * 10 + ch - '0';

                return (num & (num - 1)) == 0;
            }

            for (int i = 0; i < dig.size(); ++i) {
                if ((mask & (1 << i)) || dig[i] == '0' && !anyNonZ) continue;
                cur.push_back(dig[i]);
                if (perm(mask | (1 << i), anyNonZ || dig[i] != '0')) return true;
                cur.pop_back();
            }

            return false;
        };

        return perm(0, false);
    }
};