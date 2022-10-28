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

    inline uint64_t string_hash(const string &s) {
        auto temp{s};
        sort(temp.begin(), temp.end());
        const int n = static_cast<int>(temp.size());

        uint64_t hash = 0;
        for(int i = 0; i < n; ++i) {
            hash += (temp[i] - 'a' + 1);
            hash *= 27;
            hash = (hash % MOD + hash) % MOD;
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const uint64_t MOD = 1e9 + 7;

        unordered_map<int, vector<string>> _table;
        uint8_t curF[26] = {0,};

        for (const auto &str : strs) {
            uint64_t hash = 0u;
            memset(curF, 0u, sizeof(uint8_t) * 26);

            for (auto ch : str) ++curF[ch - 'a'];

            for (uint8_t i = 0; i < 26; ++i) {
                hash *= 103;
                hash % MOD;
                hash += curF[i] + 1;
                hash % MOD;
            }

            _table[hash].push_back(str);
        }

        vector<vector<string>> res;
        for (auto &[_, v] : _table) {
            if (!v.empty()) res.emplace_back(v);
        }

        return res;
    }
};

class Solution {
    static inline constexpr uint64_t p = 107ull;

    uint64_t get_hash(array<int, 26> &cnt) {
        uint64_t res = 0ull;
        for (auto c : cnt) res = res * p + c;

        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<uint64_t, vector<string>> mapped;

        array<int, 26> cnt{};
        for (auto &s : strs) {
            fill(cnt.begin(), cnt.end(), 0);
            for (auto ch : s) ++cnt[ch - 'a'];
            mapped[get_hash(cnt)].emplace_back(s);
        }

        vector<vector<string>> res;
        for (auto &&[_, v] : mapped) res.emplace_back(v);

        return res;
    }
};
