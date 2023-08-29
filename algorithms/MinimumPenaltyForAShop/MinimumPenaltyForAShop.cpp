#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bestClosingTime(string cs) {
        int rhs = count(cs.begin(), cs.end(), 'Y');
        int mn = rhs, ans = 0;
        int lhs = 0;
        for (int i = 0; i < cs.size(); ++i) {
            rhs -= cs[i] == 'Y';
            lhs += cs[i] == 'N';
            if (mn > lhs + rhs) {
                mn = lhs + rhs;
                ans = i + 1;
            }
        }
        return ans;
    }
};