#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();

        int idx = 0;
        for (int i = 0; i < n; ++i) {
            int freq = 1;
            for (int j = i + 1; j < n and chars[j] == chars[i]; ++j, ++i) ++freq;

            chars[idx++] = chars[i];

            if (freq > 1) {
                auto len{0};
                while (freq > 0) {
                    ++len;
                    chars[idx++] = '0' + freq % 10;
                    freq /= 10;
                }
                reverse(chars.begin() + idx - len, chars.begin() + idx);
            }
        }

        return idx;
    }
};