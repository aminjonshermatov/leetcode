#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int n = static_cast<int>(arr.size());
        sort(arr.begin(), arr.end());

        constexpr static int MOD = 1e9 + 7;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int cur = arr[i] + arr[j] + arr[k] - target;

                if (cur < 0) ++j;
                else if (cur > 0) --k;
                else if (arr[j] != arr[k]) {
                    int l = 1, r = 1;

                    while (j + 1 < n and arr[j] == arr[j + 1]) {
                        ++j;
                        ++l;
                    }

                    while (k - 1 > j and arr[k] == arr[k - 1]) {
                        --k;
                        ++r;
                    }

                    res += l * r;
                    res %= MOD;

                    ++j;
                    --k;
                } else {
                    res += (k - j + 1) * (k - j) >> 1;
                    res %= MOD;
                    break;
                }
            }
        }

        return res;
    }
};