#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n(board.size());

        auto get_coor = [&](int x) {
            auto r = n - 1 - (x - 1) / n;
            auto c = (x - 1) % n;
            if (n % 2 == r % 2) c = n - 1 - c;
            return pair(r, c);
        };

        queue<pair<int, int>> q;
        set<int> seen;
        q.emplace(1, 0);
        seen.insert(1);
        while (!q.empty()) {
            auto [X, step] = q.front(); q.pop();
            if (X == n * n) return step;

            for (int x = X + 1; x <= min(X + 6, n * n); ++x) {
                auto [r, c] = get_coor(x);
                assert(0 <= r && r < n && 0 <= c && c < n);
                auto xx = board[r][c] == -1 ? x : board[r][c];
                if (seen.count(xx) == 0) {
                    q.emplace(xx, step + 1);
                    seen.insert(xx);
                }
            }
        }

        return -1;
    }
};