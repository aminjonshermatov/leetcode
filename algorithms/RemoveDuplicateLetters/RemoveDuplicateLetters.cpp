#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = static_cast<int>(s.size());

        int count[26] = {0};
        bool visited[26] = {false};

        for (const auto ch : s) ++count[ch - 'a'];

        list<char> sL;

        for (const auto ch : s) {
            --count[ch - 'a'];

            if (visited[ch - 'a']) continue;

            while (not sL.empty() and sL.back() > ch and count[sL.back() - 'a'] > 0) {
                visited[sL.back() - 'a'] = false;
                sL.pop_back();
            }
            sL.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return {sL.begin(), sL.end()};
    }
};