#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long int result = 0;
        int stage = 0;
        bool isNegative = false;

        for (const auto ch : s) {
            if (stage == 0) {
                if (ch == ' ') continue;

                if (ch == '-' || ch == '+') {
                    stage = 1;
                    isNegative = ch == '-';
                    continue;
                }

                if (ch >= '0' && ch <= '9') {
                    result = ch - '0';
                    stage = 2;
                    continue;
                }

            }

            if (ch >= '0' && ch <= '9') {
                if (stage == 1) {
                    result = ch - '0';

                    stage = 2;
                    continue;
                }

                if (!isNegative && (result - INT_MAX / 10 > 9 || (result >= INT_MAX / 10 && (int)ch >= 55))) return INT_MAX;
                if (isNegative && (result - INT_MAX / 10 > 9 || (result >= INT_MAX / 10 && (int)ch >= 56))) return INT_MIN;

                result = result * 10 + ch - '0';
                stage = 2;
                continue;
            }

            break;
        }

        return isNegative ? -1 * result : result;
    }
};