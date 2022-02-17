#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;

        queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);

        while (q.size() > 1) {
            int i = k - 1;

            while (i--) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};