#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, res = 0;

        for (int i = 30; i >= 0; --i) {
            mask = mask | (1 << i);

            unordered_set<int> cur;

            for (const auto &n : nums) cur.insert(n & mask);

            int temp = res | (1 << i);
            for (const auto &n : cur) {
                if (cur.count(n ^ temp) > 0) {
                    res = temp;
                    break;
                }
            }
        }

        return res;
    }
};