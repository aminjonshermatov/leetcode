#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnt{};
        for (auto n : arr) ++cnt[n];

        set<int> ss;
        for (auto [_, c] : cnt) if (ss.count(c) > 0) return false; else ss.insert(c);
        return true;
    }
};