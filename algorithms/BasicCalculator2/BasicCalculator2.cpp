#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        auto prevOp{'+'};
        s += prevOp;

        int prev = 0, cur = 0, res = 0;

        for (const auto& ch : s) {
            if (ch == ' ') continue;
            if (ch >= '0' && ch <= '9') {
                cur = cur * 10 + (ch - '0');
            } else {
                if (prevOp == '+' || prevOp == '-') {
                    res += prev;
                    prev = (prevOp == '-' ? -cur : cur);
                } else if (prevOp == '*') {
                    prev *= cur;
                } else {
                    prev /= cur;
                }

                prevOp = ch;
                cur = 0;
            }
        }

        return res + prev;
    }
};