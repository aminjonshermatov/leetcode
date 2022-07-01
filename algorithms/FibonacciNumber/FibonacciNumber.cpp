#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int fib(int n) {
        int f = 0, s = 1;

        for (int i = 0; i < n; ++i) {
            int temp = s;
            s += f;
            f = temp;
        }

        return f;
    }
};