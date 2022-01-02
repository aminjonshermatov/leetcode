#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hashMap;

        int res = 0;
        for (const auto &t : time) {
            int modN = t % 60;
            res += hashMap[(60 - modN) % 60];
            ++hashMap[modN];
        }

        return res;
    }
};