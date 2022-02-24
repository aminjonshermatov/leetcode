#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        const int n = static_cast<int>(s.size());
        unordered_map<char, int> freq;

        for (const auto ch : s) ++freq[ch];

        vector<pair<int, char>> chars;
        for (const auto [ch, f] : freq) chars.emplace_back(f, ch);

        sort(chars.begin(), chars.end(), greater<>());

        string res(n, ' ');
        int idx = 0;
        for (auto [f, ch] : chars) {
            while (f-- > 0) res[idx++] = ch;
        }

        return res;
    }
};