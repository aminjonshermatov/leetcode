#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int vals[4] = {0};
        char prev = '3', cur = '2';
        int res = 0;

        for (const auto ch : s) {
            if (ch != cur) {
                vals[prev - '0'] = 0;
                prev = cur;
                cur = ch;
            }

            ++vals[cur -'0'];
            if (vals[cur - '0'] <= vals[prev - '0']) ++res;
        }

        return res;
    }
};