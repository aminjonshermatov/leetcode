#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);

        string cur;
        array<string, 9> ord;
        while (getline(iss, cur, ' ')) {
            auto idx = cur.back() - '1';
            cur.pop_back();
            ord[idx] = cur;
        }

        string res;
        for (int i = 0; i < 9; ++i) {
            if (ord[i] != "") res.append(ord[i]), res.push_back(' ');
        }
        res.pop_back();

        return res;
    }
};