#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jew;

        for (const auto ch : jewels) jew.insert(ch);

        auto res{0};
        for (const auto ch : stones) res += jew.count(ch);

        return res;
    }
};