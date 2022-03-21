#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int n = static_cast<int>(s.size());

        int lastOcc[26];

        for (int i = 0; i < n; ++i) lastOcc[s[i] - 'a'] = i;

        vector<int> res;


        for (int i = 0; i < n; ++i) {
            auto sz{1};
            auto end{lastOcc[s[i] - 'a']};

            while (i < end) {
                ++sz;
                end = max(end, lastOcc[s[++i] - 'a']);
            }

            res.push_back(sz);
        }

        return res;
    }
};