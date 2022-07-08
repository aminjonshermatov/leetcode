
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n > 1) {
            if (seen.count(n) == 1) return false;
            seen.insert(n);

            int temp = 0, rem;
            while (n > 0) {
                rem = n % 10;
                temp += rem * rem;
                n /= 10;
            }

            n = temp;
        }

        return n == 1;
    }
};