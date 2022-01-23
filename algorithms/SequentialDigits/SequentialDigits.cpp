#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        vector<int> starts = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};

        int cur = 12,
            len = 2,
            add = 11;


        while (cur <= high) {
            if (cur >= low) res.push_back(cur);

            if (cur % 10 == 9) {
                ++len;

                if (len < 10) {
                    cur = starts[len];
                    add *= 10;
                    ++add;
                } else {
                    cur = INT_MAX;
                }
            } else {
                cur += add;
            }
        }

        return res;
    }
};