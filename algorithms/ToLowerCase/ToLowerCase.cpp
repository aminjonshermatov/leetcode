#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        list<char> lowerC;

        for (const auto ch : s) {
            if (ch >= 'A' and ch <= 'Z') lowerC.push_back('a' + ch - 'A');
            else lowerC.push_back(ch);
        }

        return {lowerC.begin(), lowerC.end()};
    }
};