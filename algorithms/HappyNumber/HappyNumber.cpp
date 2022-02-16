#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uniq;

        while (n > 1) {
            if (uniq.count(n) > 0) return false;
            uniq.insert(n);

            int sum = 0;
            while (n > 0) {
                const int mod = n % 10;
                n /= 10;
                sum += mod * mod;
            }

            n = sum;
        }

        return n == 1;
    }
};