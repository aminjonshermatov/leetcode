#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for (auto ch : s) if (!res.empty() && ch == res.back()) res.pop_back(); else res.push_back(ch);
        return res;
    }
};