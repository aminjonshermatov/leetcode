#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        const int N(data.size());

        for (int i = 0; i < N; ++i) {
            if (i + 1 < N && (data[i] >> 5) == 0b110) {
                if ((data[i + 1] >> 6) != 0b10) return false;
                ++i;
            } else if (i + 2 < N && (data[i] >> 4) == 0b1110) {
                for (int j = 1; j <= 2; ++j)
                    if ((data[i + j] >> 6) != 0b10) return false;
                i += 2;
            } else if (i + 3 < N && (data[i] >> 3) == 0b11110) {
                for (int j = 1; j <= 3; ++j)
                    if ((data[i + j] >> 6) != 0b10) return false;
                i += 3;
            } else if ((data[i] >> 7) != 0) return false;
        }

        return true;
    }
};