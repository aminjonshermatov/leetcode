#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aR = a.size() - 1,
            bR = b.size() - 1,
            rem = 0;

        string res;

        while (aR >= 0 && bR >= 0) {
            int temp = a[aR--] - '0' + b[bR--] - '0' + rem;

            res.insert(res.begin(), (temp % 2 != 0 ? '1' : '0'));
            rem = temp / 2;
        }

        while (aR >= 0) {
            int temp = a[aR--] - '0' + rem;

            res.insert(res.begin(), (temp % 2 != 0 ? '1' : '0'));
            rem = temp / 2;
        }

        while (bR >= 0) {
            int temp = b[bR--] - '0' + rem;

            res.insert(res.begin(), (temp % 2 != 0 ? '1' : '0'));
            rem = temp / 2;
        }

        if (rem != 0) res.insert(res.begin(), '1');

        return res;
    }
};