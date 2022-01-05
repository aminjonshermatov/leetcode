#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> hash;
        for (const auto &ss : wordDict) hash[ss.size()].push_back(ss);
        unordered_map<int, bool> cache;
        cache[s.size()] = true;

        function<bool(int)> dfs = [&s, &hash, &cache, &dfs](int idx) -> bool {
            if (cache.count(idx) > 0) return cache[idx];

            bool res = false;

            for (int i = idx; i < s.size() && !res; ++i) {
                if (hash.count(i - idx + 1) == 0) continue;

                auto it = find(hash[i - idx + 1].begin(), hash[i - idx + 1].end(), s.substr(idx, i - idx + 1));

                if (it != hash[i - idx + 1].end()) res = dfs(i + 1);
            }

            return cache[idx] = res;
        };

        return dfs(0);
    }
};