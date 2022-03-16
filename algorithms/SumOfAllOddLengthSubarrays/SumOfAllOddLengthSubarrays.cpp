#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        auto sum{0};

        for (int len = 1; len <= arr.size(); len += 2) {
            auto l{0};
            auto r{0};

            auto window{0};

            while (r < len) window += arr[r++];
            sum += window;

            while (r < arr.size()) {
                window -= arr[l++];
                window += arr[r++];

                sum += window;
            }
        }

        return sum;
    }
};