#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>&& arr) {
        int len = (int)arr.size();
        int l = -1, r = len;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mid == 0) ++mid;

            if (arr[mid] > arr[mid - 1]) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }
};