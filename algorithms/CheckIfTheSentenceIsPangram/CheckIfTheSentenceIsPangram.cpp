#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkIfPangram(string s) {
        array<int, 26> fr;
        fill(fr.begin(), fr.end(), 0);

        for (auto ch : s) ++fr[ch - 'a'];
        return all_of(fr.begin(), fr.end(), [](auto c) -> bool { return c > 0; });
    }
};