#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int   r = static_cast<int>(isConnected.size()),
                    c = static_cast<int>(isConnected[0].size());

        queue<int> q;
        int count = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (isConnected[i][j] == 1) {
                    if (q.empty()) ++count;
                    isConnected[i][j] = 0;
                    q.push(j);
                }
            }

            while (not q.empty()) {
                auto y = q.front(); q.pop();

                for (int j = 0; j < c; ++j) {
                    if (isConnected[y][j] == 1) {
                        q.push(j);
                        isConnected[y][j] = 0;
                    }
                }
            }
        }

        return count;
    }
};