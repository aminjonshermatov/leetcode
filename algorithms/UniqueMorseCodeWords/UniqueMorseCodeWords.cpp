#include "bits/stdc++.h"

using namespace std;

class Solution {
    array<string, 26> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                               "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                               "-.--", "--.."};
public:
    int uniqueMorseRepresentations(vector <string> &words) {
        string cur;
        cur.reserve(12);
        unordered_set <string> uniq;

        for (auto &w: words) {
            for (auto ch: w) cur.append(morse[ch - 'a']);
            uniq.insert(cur);
            cur.clear();
        }

        return uniq.size();
    }
};