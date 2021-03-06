#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int new_num = 0;

            while (num > 0) {
                new_num += num % 10;
                num /= 10;
            }
            num = new_num;
        }

        return num;
    }
};