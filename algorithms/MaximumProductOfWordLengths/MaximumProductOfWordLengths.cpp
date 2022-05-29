#include "bits/stdc++.h"

using namespace std;

class Solution {
    int masks[1000];

public:
    int maxProduct(vector<string>& words) {
        const int n(words.size());

        for (int i = 0; i < n; ++i) {
            int cur = 0 ;
            for (const auto ch : words[i]) cur |= (1 << (ch - 'a'));
            masks[i] = cur;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) ans = max<int>(ans, words[i].size() * words[j].size());
            }
        }

        return ans;
    }
};