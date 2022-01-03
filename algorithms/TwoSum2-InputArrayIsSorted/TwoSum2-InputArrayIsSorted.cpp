#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < numbers.size(); ++i) {
            if (hash.count(target - numbers[i]) > 0) return {hash[target - numbers[i]], i + 1};
            hash[numbers[i]] = i + 1;
        }

        return {};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int diff = target - numbers[l] - numbers[r];

            if (diff < 0) --r;
            else if (diff > 0) ++l;
            else break;
        }

        return {l + 1, r + 1};
    }
};