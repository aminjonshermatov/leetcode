#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res;
        for (auto ch : s) {
            if (!res.empty()
                && ((islower(res.back()) && isupper(ch) && tolower(ch) == res.back())
                    || (islower(ch) && isupper(res.back()) && toupper(ch) == res.back()))) res.pop_back();
            else res.push_back(ch);
        }

        return res;
    }
};