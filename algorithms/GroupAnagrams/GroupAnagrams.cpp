#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint64_t, vector<string>> h_map;

        for (const auto &s : strs) h_map[string_hash(s)].push_back(s);

        vector<vector<string>> res;
        for (const auto &[_, v] : h_map) res.emplace_back(v);

        return res;
    }

    static constexpr uint64_t MOD = 1e9 + 7;

    inline uint32_t string_hash(const string &s) {
        auto temp{s};
        sort(temp.begin(), temp.end());
        const int n = static_cast<int>(temp.size());

        uint32_t hash = 0;
        for(int i = 0; i < n; ++i) {
            hash += (temp[i] - 'a' + 1);
            hash *= 27;
            hash = (hash % MOD + hash) % MOD;
        }

        return hash;
    }
};