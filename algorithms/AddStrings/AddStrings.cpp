#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        deque<char> deq;

        const int   n = static_cast<int>(num1.size()),
                m = static_cast<int>(num2.size());

        int i = n - 1, j = m - 1, rem = 0;

        while (i >= 0 and j >= 0) {
            const int cur = (num1[i--] - '0') + (num2[j--] - '0') + rem;

            deq.push_front('0' + cur % 10);
            rem = cur / 10;
        }

        while (i >= 0) {
            const int cur = (num1[i--] - '0') + rem;

            deq.push_front('0' + cur % 10);
            rem = cur / 10;
        }

        while (j >= 0) {
            const int cur = (num2[j--] - '0') + rem;

            deq.push_front('0' + cur % 10);
            rem = cur / 10;
        }

        if (rem != 0) deq.push_front('0' + rem);

        return string{deq.begin(), deq.end()};
    }
};