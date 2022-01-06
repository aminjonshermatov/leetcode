#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> state(1001, 0);

        for (const auto& it : trips) {
            state[it[1]] += it[0];
            state[it[2]] -= it[0];
        }

        int sum = 0;
        for (const auto n : state) {
            sum += n;
            if (sum > capacity) return false;
        }

        return true;
    }
};