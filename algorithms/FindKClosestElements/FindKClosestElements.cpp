#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](const auto lhs, const auto rhs) {
            if (abs(lhs - x) == abs(rhs - x)) return lhs < rhs;
            return abs(lhs - x) < abs(rhs - x);
        });

        arr.erase(arr.begin() + k, arr.end());
        sort(arr.begin(), arr.end());

        return arr;
    }
};