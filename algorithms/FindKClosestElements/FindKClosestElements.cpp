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

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N(arr.size());
        vector<int> res;
        res.reserve(k);

        auto r = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        auto l = r - 1;

        while (res.size() < k && (l >= 0 || r < N)) {
            if (l >= 0 && r < N) {
                if (abs(arr[l] - x) < abs(arr[r] - x) || abs(arr[l] - x) == abs(arr[r] - x) && arr[l] < arr[r])
                    res.emplace_back(arr[l--]);
                else
                    res.emplace_back(arr[r++]);
            } else if (l >= 0) res.emplace_back(arr[l--]);
            else if (r < N) res.emplace_back(arr[r++]);
        }

        sort(res.begin(), res.end());
        return res;
    }
};