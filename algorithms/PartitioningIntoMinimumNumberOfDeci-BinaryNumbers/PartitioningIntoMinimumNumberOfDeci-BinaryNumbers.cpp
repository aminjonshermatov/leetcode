#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        return accumulate(n.begin(), n.end(),
                          0, [](auto &acc, auto &el) { return max(acc, el - '0'); });
    }
};