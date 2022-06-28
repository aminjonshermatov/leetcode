#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0,};

        for (const auto ch : s) ++freq[ch - 'a'];

        sort(freq, freq + 26);

        int ans = 0;
        set<int> ss;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0 && ss.count(freq[i]) == 0) ss.insert(freq[i]);
            else {
                for (int k = 1; k <= freq[i]; ++k) {
                    if (ss.count(freq[i] - k) == 0) {
                        if (freq[i] != k) ss.insert(freq[i] - k);
                        ans += k;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};