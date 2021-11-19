#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        return letterCasePermutation(s, 0);
    }

    vector<string> letterCasePermutation(string s, int pos) {
        char temp = s[pos];
        bool isAlph = false;
        if (temp >= 'a' && temp <= 'z') {
            temp = 'A' + temp - 'a';
            isAlph = true;
        } else if (temp >= 'A' && temp <= 'Z') {
            temp = 'a' + temp - 'A';
            isAlph = true;
        }

        if (pos + 1 == s.size()) {
            if (isAlph) {
                string another = s;
                another[pos] = temp;
                return {s, another};
            }

            return {s};
        }

        vector<string> res = letterCasePermutation(s, pos + 1);

        int len = res.size();

        for (int i = 0; i < len && isAlph; ++i) {
            string s = res[i];
            s[pos] = temp;
            res.push_back(s);
        }

        return res;
    }
};