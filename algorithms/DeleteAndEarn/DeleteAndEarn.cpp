#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> counts;

        for (const auto n : nums) ++counts[n];

        set<int> sorted;
        for (const auto [k, _] : counts) sorted.insert(k);

        int earn1 = 0, earn2 = 0, prev = -1;
        for (const auto n : sorted) {
            auto temp{earn2};
            auto cur{n * counts[n]};

            if (prev != -1 and n == prev + 1) earn2 = max(earn2, cur + earn1);
            else earn2 += cur;

            prev = n;
            earn1 = temp;
        }

        return earn2;
    }
};