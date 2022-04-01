#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = static_cast<int>(s.size());

        for (int l = 0, r = n - 1; l < r; ++l, --r) swap(s[l], s[r]);
    }
};