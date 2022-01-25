#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();

        if (len < 3) return false;

        bool peekedTop = false;

        for (int i = 1; i < len; ++i) {
            if (peekedTop) {
                if (arr[i - 1] <= arr[i]) return false;
            } else {
                if (arr[i - 1] == arr[i]) return false;
                if (arr[i - 1] > arr[i]) {
                    if (i == 1) return false;
                    peekedTop = true;
                }
            }
        }

        return peekedTop;
    }
};