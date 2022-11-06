#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline bool check(int k) {
        int temp = k;
        while (temp > 0) {
            if (auto rem = temp % 10; rem == 0 || k % rem != 0) return false;
            temp /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> res;
        for (int i = l; i <= r; ++i) if (check(i)) res.emplace_back(i);

        return res;
    }
};