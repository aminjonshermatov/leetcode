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
        const int n = static_cast<int>(numbers.size());

        auto l{0};
        auto r{n - 1};

        while (l < r) {
            auto cur{numbers[l] + numbers[r]};

            if (cur == target) return {l + 1, r + 1};
            else if (cur < target) ++l;
            else --r;
        }

        return {};
    }
};