#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int add) {
        const int n(c.size());

        vector<int> A(n);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&](auto lhs, auto rhs) { return c[lhs] - r[lhs] < c[rhs] - r[rhs]; });
        for_each(A.begin(), A.end(), [&](auto i) {
            auto to_add = min(add, c[i] - r[i]);
            r[i] += to_add;
            add -= to_add;
        });
        return count_if(A.begin(), A.end(), [&](auto i) { return r[i] == c[i]; });
    }
};