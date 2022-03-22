#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        list<char> s;

        while (n > 0) {
            auto cur{k - --n};
            cur = min(26, cur);
            k -=cur;

            s.push_back('a' + cur - 1);
        }

        return {s.rbegin(), s.rend()};
    }
};