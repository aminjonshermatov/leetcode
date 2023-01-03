#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n(strs.size());
        const int m(strs[0].size());

        vector<char> last(m, 'a' - 1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (strs[i][j] < last[j]) {
                    if (last[j] == 'z' + 1) continue;
                    last[j] = 'z' + 1;
                    ++ans;
                } else last[j] = strs[i][j];
            }
        }

        return ans;
    }
};