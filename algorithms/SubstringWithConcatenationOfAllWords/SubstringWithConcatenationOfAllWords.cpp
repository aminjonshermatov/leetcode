#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const size_t N(s.size());
        const size_t M(words.size());
        const size_t K(words.front().size());
        const size_t MK = M * K;

        unordered_map<string, int> freq;
        for (auto &w : words) ++freq[w];

        vector<int> res;
        // O(N)
        for (int i = 0; i + MK <= N; ++i) {
            auto cp = freq;
            bool ok = true;
            // O(M*K)
            for (int j = 0; j < M && ok; ++j) {
                auto ss = s.substr(i + K * j, K);
                auto it = cp.find(ss);
                if (it == cp.end() || it->second == 0) ok = false;
                else --it->second;
            }
            if (ok) res.push_back(i);
        }

        return res;
    }
};