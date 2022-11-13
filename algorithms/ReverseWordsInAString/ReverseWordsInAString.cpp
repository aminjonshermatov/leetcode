#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string rev = s;

        reverse(rev.begin(), rev.end());
        const int N(s.size());
        for (int i = 0; i < N; ++i) {
            if (rev[i] == ' ') continue;
            int j = rev.find(' ', i + 1);
            if (j == string::npos) j = N;
            reverse(rev.begin() + i, rev.begin() + j);
            i = j;
        }

        int i = 0;
        char prev = ' ';
        for (int j = 0; j < N; ++j) {
            if (rev[j] != ' ' || prev != ' ') rev[i] = rev[j], prev = rev[i++];;
        }
        rev.erase(i);
        if (!rev.empty() && rev.back() == ' ') rev.pop_back();

        return rev;
    }
};