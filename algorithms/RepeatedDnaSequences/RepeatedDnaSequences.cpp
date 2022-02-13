#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int       n = static_cast<int>(s.size());
        constexpr int   k = 10;

        if (n <= 10) return {};

        vector<string> res;
        unordered_map<string, int> uniq;
        list<char> cur;

        for (int i = 0; i < n; ++i) {
            cur.push_back(s[i]);

            if (i >= 9) {
                string temp{cur.begin(), cur.end()};

                if (uniq[temp] == 1) {
                    res.emplace_back(temp);
                    uniq[temp] = INT_MIN;
                }
                else ++uniq[temp];

                cur.pop_front();
            }
        }

        return res;
    }
};