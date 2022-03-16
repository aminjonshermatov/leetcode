#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int n = static_cast<int>(seats.size());

        vector<int> pref(n), suff(n);

        pref[0] = seats[0] == 1 ? 0 : -1;
        for (int i = 1; i < n; ++i) {
            pref[i] = seats[i] == 1 ? i : pref[i - 1];
        }

        suff[n - 1] = seats[n - 1] == 1 ? n - 1 : -1;
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = seats[i] == 1 ? i : suff[i + 1];
        }

        int maxD = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) continue;

            if (pref[i] == -1 and suff[i] != -1) maxD = max(maxD, suff[i] - i);
            else if (suff[i] == -1 and pref[i] != -1) maxD = max(maxD, i - pref[i]);
            else maxD = max(maxD, min(i - pref[i], suff[i] - i));
        }

        return maxD;
    }
};