#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        for (int i = 0; i < arr.size() - 1; ++i) minDiff = min(minDiff, arr[i + 1] - arr[i]);

        vector<vector<int>> res;

        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] + minDiff == arr[i + 1]) res.push_back({arr[i], arr[i + 1]});
        }

        return res;
    }
};