#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> bitsCount;

        for (const auto num : arr) {
            auto temp{num};
            auto count{0};

            while (temp > 0) {
                count += temp & 1;
                temp >>= 1;
            }

            bitsCount[num] = count;
        }

        sort(arr.begin(), arr.end(), [&bitsCount](const auto lhs, const auto rhs) -> bool {
            if (bitsCount[lhs] == bitsCount[rhs]) return lhs < rhs;
            return bitsCount[lhs] < bitsCount[rhs];
        });

        return arr;
    }
};