#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num > 0) {
            if (num & 1) --num;
            else num >>= 1;
            ++ans;
        }

        return ans;
    }
};