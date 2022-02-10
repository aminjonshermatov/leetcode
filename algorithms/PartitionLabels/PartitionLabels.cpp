#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int n = static_cast<int>(s.size());
        vector<int> res;
        int starts[26] = {-1};

        for (int i = 0; i < n; ++i) starts[s[i] - 'a'] = i;

        int idx = 0;
        while (idx < n) {
            int start = idx, end = starts[s[idx] - 'a'];
            while (start <= end and start < n) end = max(end, starts[s[start++] - 'a']);

            res.push_back(start - idx);
            idx = start;
        }

        return res;
    }
};