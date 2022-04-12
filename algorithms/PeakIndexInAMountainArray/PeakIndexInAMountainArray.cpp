#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int n = static_cast<int>(arr.size());

        int lo = 0, hi = n;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]) return mid;
            else if (arr[mid] < arr[mid + 1]) lo = mid + 1;
            else hi = mid;
        }

        return {};
    }
};